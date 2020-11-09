/*
   Robot wiggles, without using delays. Wiggle action is in a class.
   the class is implemented as a state machine
*/

#include <Arduino.h>
#include <stdint.h>
#include "SCMD.h"
#include "SCMD_config.h" //Contains #defines for common SCMD register names and values
#include "Wire.h"

SCMD myMotorDriver; //This creates the main object of one motor driver and connected slaves.
#define LEFT_MOTOR 0
#define RIGHT_MOTOR 1

void stopMotors() {
  myMotorDriver.setDrive( LEFT_MOTOR, 0, 0); //Stop motor
  myMotorDriver.setDrive( RIGHT_MOTOR, 0, 0); //Stop motor
}

void leftForward(int speed) {
  myMotorDriver.setDrive( LEFT_MOTOR, 0, speed);
}

void rightForward(int speed) {
  myMotorDriver.setDrive( RIGHT_MOTOR, 0, speed);
}

/*
   Wiggle class
   Methods include:
   - .init(repetitions, duration, innerSpeed, outerSpeed)
   - .update()
   - .inProgress()
*/

class Wiggler {
    // Class variables
    unsigned long startedThisWiggleAt = 0;
    unsigned long desiredWiggleDuration;
    int desiredWiggleRepetitions;
    int state = 0;
    unsigned long now;
    int desiredInnerSpeed ;
    int desiredOuterSpeed ;

    /*
       Wiggle states:

       0 - just created; next state: 0
       1 - start a left wiggle; next state: 2
       2 - next state: 3, if time expired
       3 - start a right wiggle; next state: 4
       4 - next state: 5, if time expired
       5 - decrement repetitions; next state: if repetitions == 0, state 6 otherwise: state 1
       6 - turn motors off; next state: 0
    */

  public:

    Wiggler() { // nothing to do in constructor
      state = 0;
    }

    void init( int _repetitions, int _duration,  int _innerSpeed, int _outerSpeed ) {
      desiredWiggleRepetitions = _repetitions;
      desiredWiggleDuration = _duration;
      desiredInnerSpeed = _innerSpeed;
      desiredOuterSpeed = _outerSpeed;
      state = 1;
    }

    void update() {

      // for debugging
//      Serial.print("state = ");
//      Serial.print(state);
//      Serial.print("\t time = ");
//      Serial.print(millis());
//      Serial.print("\t repetitions = ");
//      Serial.print(desiredWiggleRepetitions);
//      Serial.println();

      switch (state) {
        case 0:
          state = 0;
          break;
        case 1:
          wiggleLeft();
          startedThisWiggleAt = millis();
          state = 2;
          break;
        case 2:
          now = millis();
          if ((now - startedThisWiggleAt) >= desiredWiggleDuration) {
            state = 3;
          }
          break;
        case 3:
          wiggleRight();
          startedThisWiggleAt = millis();
          state = 4;
          break;
        case 4:
          now = millis();
          if ((now - startedThisWiggleAt) >= desiredWiggleDuration) {
            state = 5;
          }
          break;
        case 5:
          desiredWiggleRepetitions--;
          if (desiredWiggleRepetitions) {
            state = 1; // do another wiggle
          } else {
            state = 6; // we're done
          }
          break;
        case 6:
          stopMotors();
          state = 0;
          break;
      }
    }

    boolean inProgress() {
      if (state == 0)
        return  false;
      else
        return true;
    }

  private:
    void wiggleRight() {
      leftForward(desiredOuterSpeed);
      rightForward(desiredInnerSpeed);
    }
    void wiggleLeft() {
      leftForward(desiredInnerSpeed);
      rightForward(desiredOuterSpeed);
    }
};

Wiggler myWiggler;

void setup()
{
  Serial.begin(9600);

  initMotorDriver();

  myWiggler.init(4, 500, 10, 100); // repetitions, duration,  innerSpeed, outerSpeed
}

void loop()
{
  myWiggler.update();
  Serial.println(myWiggler.inProgress());
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
  Serial.print("Waiting for motor driver peripheral enumeration...");
  while ( myMotorDriver.ready() == false )
    ;
  Serial.println("motor driver peripheral enumeration done.");

  while ( myMotorDriver.busy() ) {
    Serial.println("waiting for motor driver to not be busy");
  }
  Serial.println("motor driver ready");
  Serial.println();
  myMotorDriver.enable(); //Enables the output driver hardware
  stopMotors();
}
