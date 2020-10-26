/*
  Using a state machine to determine what the robot should do next

  Based on examples from SparkFun for the MP3 Trigger
  and the Serial Controlled Motor Driver (modified for QWIIC)

  Change log

  26 10 2020 - Michael Shiloh - initial creation

  This example is in the public domain

  State Action                        stay here until     Next state
  0     -                             button pressed      1
  1     -                             button released     2
  2     speak FLAVIUS (F001.mp3)      -                   3
  3     -                             FLAVIUS finished    4
  4     move to side A                movement finished   5
  5     speak First Commoner          First Commoner      6
  6     move to side B                movement finished   7
  7     speak MARULLUS                MARULLUS finished   0

*/

#include <Arduino.h>
#include <stdint.h>
#include "Wire.h" // for QWIIC communication

// Motor driver
#include "SCMD.h"
#include "SCMD_config.h" //Contains #defines for common SCMD register names and values
SCMD myMotorDriver; //This creates the main object of one motor driver


// MP3 trigger
#include "SparkFun_Qwiic_MP3_Trigger_Arduino_Library.h" //http://librarymanager/All#SparkFun_MP3_Trigger
MP3TRIGGER mp3; // MP3 Trigger object

#include <SparkFun_Qwiic_Button.h>
QwiicButton button;

// for our state machine!
int state = 0;

// for timed movements; see below (way below)
unsigned long movementStartedAtMillis = 0;
unsigned long movementDesiredMillisDuration = 0;
boolean movementInProcess = false;


void setup()
{
  Serial.begin(9600);

  initButton();
  initMotorDriver();
  initMP3Trigger();
}


void loop()
{
  /*
     BUG!
  */
  // If I remove this delay state 3 does not wait for the file to finish playing (sometimes)
  // Need to understand this
  //delay(100);

  // for debugging
  Serial.print("state = ");
  Serial.print(state);
  Serial.print("\t time = ");
  Serial.print(millis());
  Serial.println();

  switch (state) {
    case 0:
      if (button.isPressed()) {
        state = 1;
      }
      break;

    case 1:
      if (!button.isPressed()) {
        state = 2;
      }
      break;

    case 2:
      mp3.playFile(1);
      delay(1);
      state = 3;
      break;

    case 3:
      if (!mp3.isPlaying()) {
        state = 4;
      }
      break;

    // initiated movement to other side
    case 4:
      moveForwardTimedStart(100, 3000); // speed, time
      state = 5;
      break;

    // wait for movement to finish
    case 5:
      moveForwardTimedUpdate();
      if (!movementInProcess) {
        state = 0;
      } // This one!
      break;

    default:
      Serial.println("invalid state; freezing");
      while (1)
        ;
  }
}

/*
    Initialization functions, copied almost directly much from the examples
*/

void initButton() {

  Wire.begin(); //Join I2C bus
  //I would assume motor driver and mp3 trigger also do this; apparently there is no harm in multiple calls

  //check if button will acknowledge over I2C
  if (button.begin() == false) {
    Serial.println("Device did not acknowledge! Freezing.");
    while (1);
  }
  Serial.println("Button acknowledged.");
}


void initMotorDriver() {

  //***** Configure the Motor Driver's Settings *****//
  //  .commInter face is I2C_MODE
  myMotorDriver.settings.commInterface = I2C_MODE;

  //  set address if I2C configuration selected with the config jumpers
  myMotorDriver.settings.I2CAddress = 0x5D; //config pattern is "1000" (default) on board for address 0x5D

  //  set chip select if SPI selected with the config jumpers
  myMotorDriver.settings.chipSelectPin = 10;

  //*****initialize the driver get wait for idle*****//
  while ( myMotorDriver.begin() != 0xA9 ) //Wait until a valid ID word is returned
  {
    Serial.println( "ID mismatch, trying again" );
    delay(500);
  }
  Serial.println( "ID matches 0xA9" );

  //  Check to make sure the driver is done looking for slaves before beginning
  Serial.print("Waiting for motor driver slave enumeration...");
  while ( myMotorDriver.ready() == false )
    ;
  Serial.println("motor driver slave enumeration done.");

  while ( myMotorDriver.busy() ) {
    Serial.println("waiting for motor driver to not be busy");
  }
  myMotorDriver.enable(); //Enables the output driver hardware
  motorsStop();
}

void initMP3Trigger()
{

  //Check to see if Qwiic MP3 is present on the bus
  if (mp3.begin() == false)
  {
    Serial.println("Qwiic MP3 failed to respond. Please check wiring and possibly the I2C address. Freezing...");
    while (1);
  }

  mp3.setVolume(31); //Volume can be 0 (off) to 31 (max)

  Serial.print("Song count: ");
  Serial.println(mp3.getSongCount());
}

/*
   Motor helper functions
*/

/*
   First the basics for each wheel
*/

/*
     BUG! (or at least something suspicious)
*/
// Why is speed red? Is it a global variable?
// Need to understand this
void rightForward(int speed)
{
  myMotorDriver.setDrive( 0, 1, speed);
}

void rightBackward(int speed)
{
  myMotorDriver.setDrive( 0, 0, speed);
}

void leftForward(int speed)
{
  myMotorDriver.setDrive( 1, 0, speed);
}

void leftBackward(int speed)
{
  myMotorDriver.setDrive( 1, 1, speed);
}


/*
   Now combine the each wheel functions
   to move the whole robot
   Also to stop the robot
*/

void moveForward( int speed) {
  rightForward(speed);
  leftForward(speed);
}

void moveBackward( int speed) {
  rightBackward(speed);
  leftBackward(speed);
}

void turnRight(int speed)
{
  leftForward(speed);
  rightBackward(speed);
}

void turnLeft(int speed)
{
  rightForward(speed);
  leftBackward(speed);
}

void motorsStop() {
  moveForward(0);
}

/*
   Now more complex. Move for a certain amount of time.
   These are non-blocking functions which means that we need
   1) A global time variable which keeps track of how much time it's been moving
   2) A global boolean variable which tells us that the movement is happening or not
   3) A function to start the movement
   4) A function to update the movement
*/


void moveForwardTimedStart(int speed, int time) {

  // Defensive programming: we should initiate a movement if we are already moving
  if (movementInProcess) {
    Serial.println("Movement initiated but we are already moving. Freezing");
    while (1)
      ;
  }

  // everything seems OK so start the movement
  moveForward(speed);
  movementStartedAtMillis = millis();
  movementDesiredMillisDuration = time;
  movementInProcess = true;
}

void moveForwardTimedUpdate() {
  int currentMillis = millis();

  // Is it time to stop moving?
  if (currentMillis - movementStartedAtMillis >= movementDesiredMillisDuration) {
    motorsStop();
    movementInProcess = false;
    Serial.println("time expired");
  }
}
