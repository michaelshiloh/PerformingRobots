/*********************************************************************
  Robot control for Open Studios

  Drawing on examples from:
  - Adafruit DCMotorTest
  - Adafruit StepperTest
  - Adafruit Bluefruit controller
*********************************************************************/
#include <Servo.h>
#include <string.h>
#include <Arduino.h>
#include <SPI.h>
#if not defined (_VARIANT_ARDUINO_DUE_X_) && not defined (_VARIANT_ARDUINO_ZERO_)
#include <SoftwareSerial.h>
#endif

#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "Adafruit_BluefruitLE_UART.h" // perhaps not necessary

#include "BluefruitConfig.h"

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Create the motor shield object from the Adafruit_MotorShield class
Adafruit_MotorShield AFMS_60 = Adafruit_MotorShield();
Adafruit_MotorShield AFMS_61 = Adafruit_MotorShield(0x61);

// Create pointers to two motor objects from the Adafruit_DCMotor class
Adafruit_DCMotor * leftMotor = AFMS_60.getMotor(3);
Adafruit_DCMotor * rightMotor = AFMS_60.getMotor(4);
Adafruit_DCMotor * drum = AFMS_61.getMotor(1);
Adafruit_DCMotor * dragon = AFMS_61.getMotor(2);

// Stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
Adafruit_StepperMotor *myMotor = AFMS_61.getStepper(200, 2);

/* See original Bluefruit controller example for an explanation */
// turning this off to avoid losing the firmware update every time.
#define FACTORYRESET_ENABLE         0
#define MINIMUM_FIRMWARE_VERSION    "0.6.6"
#define MODE_LED_BEHAVIOUR          "MODE"
/*=========================================================================*/

// Create the bluefruit object,

/* ...hardware SPI, using SCK/MOSI/MISO hardware SPI pins and then user selected CS/IRQ/RST */
Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);


/**************************************************************
   Global Variables
*/

// The amount of time to turn right. I made this global so that I could adjust
// and have it survive loops, but in general global variables like this are a bad
// idea. What's a better way to do this?
int rightTurnTime90Degrees;
// To control the speeds of the drumming and the dragon's wings flapping
int dragonSpeed = 100;
int drumSpeed = 100;
int angle=0;
/**************************************************************/




/**************************************************************
   Global Constants and Pin Usage
*/

/*
    Bluefruit uses pins 13, 12, 11, 8, 7, and 4 (check)
*/

/*
   Motor shield uses pins A5 and A6 (I2C)
*/

/*
  NeoPixels
*/
const int NEO_PIXEL_PIN = 6;
const int NEO_PIXEL_COUNT = 26; // How many NeoPixels are attached to the Arduino?
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NEO_PIXEL_COUNT, NEO_PIXEL_PIN, NEO_GRB + NEO_KHZ800);

const int PIXEL_BUTTON_8_LED = 17;
const int PIXEL_BUTTON_7_LED = 16;
const int PIXEL_BUTTON_6_LED = 15;
const int PIXEL_BUTTON_5_LED = 14;
const int PIXEL_BUTTON_4_LED = 13;
const int PIXEL_BUTTON_3_LED = 12;
const int PIXEL_BUTTON_2_LED = 11;
const int PIXEL_BUTTON_1_LED = 10;
const int PIXEL_AFMS_61_LED = 4;
const int PIXEL_AFMS_60_LED = 3;
const int PIXEL_BLE_LED = 2;
const int PIXEL_SERIAL_LED = 1;
const int PIXEL_NEO_PIXEL_LED = 0;

const int PIXEL_COLOR_RED = pixels.Color(10, 0, 0);
const int PIXEL_COLOR_GREEN = pixels.Color(0, 50, 0);
const int PIXEL_COLOR_BLUE = pixels.Color(0, 0, 10);
const int PIXEL_COLOR_YELLOW = pixels.Color(50, 50, 10);
const int PIXEL_COLOR_PRESSED = PIXEL_COLOR_BLUE;
const int PIXEL_COLOR_RELEASED = PIXEL_COLOR_YELLOW;

/**************************************************************/
/*!
(SIBA) Added classes for the Servo swwep functions
*/ 
/**************************************************************/

class Sweeper
{
    Servo servo;              // the servo
    int pos;              // current servo position
    int increment;        // increment to move for each interval
    int lowIncrement;
    int highIncrement;
    int  updateInterval;      // interval between updates
    unsigned long lastUpdate; // last update of position

  public:
    Sweeper(int interval)
    {
      updateInterval = interval;
      lowIncrement = 1;
      highIncrement = 5;
    }

    void Attach(int pin)
    {
      servo.attach(pin);
    }

    void Detach()
    {
      servo.detach();
    }

    void Update()
    {
      if ((millis() - lastUpdate) > updateInterval) // time to update
      {
        lastUpdate = millis();
        //increment=1;
        pos += increment;
        servo.write(pos);
        Serial.println(pos);
        if (pos >= 135) 
        {
          increment = - lowIncrement;
        }
        else if ((pos <= 0)) // end of sweep
        {
          // reverse direction
          //servo.write(0);
          increment = highIncrement;
        }
      }
    }
};

Sweeper swee(15);


// A small helper
void error(const __FlashStringHelper*err) {
  Serial.println(err);
  while (1);
}

// function prototypes over in packetparser.cpp
uint8_t readPacket(Adafruit_BLE *ble, uint16_t timeout);
float parsefloat(uint8_t *buffer);
void printHex(const uint8_t * data, const uint32_t numBytes);

// the packet buffer
extern uint8_t packetbuffer[];


/**************************************************************************/
/*!
    @brief  Sets up the HW an the BLE module (this function is called
            automatically on startup)
*/
/**************************************************************************/
void setup(void)
{
  while (!Serial);  // required for Flora & Micro
  delay(500);

  pixels.begin(); // This initializes the NeoPixel library.
  pixels.setPixelColor(PIXEL_NEO_PIXEL_LED, PIXEL_COLOR_GREEN);
  pixels.show(); // This sends the updated pixel color to the hardware.

  Serial.begin(115200);
  Serial.println(F("Adafruit Bluefruit App Controller Example"));
  Serial.println(F("-----------------------------------------"));
  pixels.setPixelColor(PIXEL_SERIAL_LED, PIXEL_COLOR_GREEN);
  pixels.show();

  /* Initialise Bluetooth module */
  Serial.print(F("Initialising the Bluefruit LE module: "));

  if ( !ble.begin(VERBOSE_MODE) )
  {
    error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
  }
  Serial.println( F("OK!") );
  pixels.setPixelColor(PIXEL_BLE_LED, PIXEL_COLOR_GREEN); // BLE init
  pixels.show();

  if ( FACTORYRESET_ENABLE )
  {
    /* Perform a factory reset to make sure everything is in a known state */
    Serial.println(F("Performing a factory reset: "));
    if ( ! ble.factoryReset() ) {
      error(F("Couldn't factory reset"));
    }
  }

  /* Disable command echo from Bluefruit */
  ble.echo(false);

  Serial.println("Requesting Bluefruit info:");
  /* Print Bluefruit information */
  ble.info();

  Serial.println(F("Please use Adafruit Bluefruit LE app to connect in Controller mode"));
  Serial.println(F("Then activate/use the sensors, color picker, game controller, etc!"));
  Serial.println();

  ble.verbose(false);  // debug info is a little annoying after this point!

  /* Wait for connection */
  while (! ble.isConnected()) {
    pixels.setPixelColor(PIXEL_BLE_LED, PIXEL_COLOR_RED);
    pixels.show();
    delay(500);
  }
  // Change BLE LED to BLUE when connected
  pixels.setPixelColor(PIXEL_BLE_LED, PIXEL_COLOR_BLUE);
  pixels.show();

  Serial.println(F("******************************"));

  // LED Activity command is only supported from 0.6.6
  if ( ble.isVersionAtLeast(MINIMUM_FIRMWARE_VERSION) )
  {
    // Change Mode LED Activity
    Serial.println(F("Change LED activity to " MODE_LED_BEHAVIOUR));
    ble.sendCommandCheckOK("AT+HWModeLED=" MODE_LED_BEHAVIOUR);
  }

  // Set Bluefruit to DATA mode
  Serial.println( F("Switching to DATA mode!") );
  ble.setMode(BLUEFRUIT_MODE_DATA);

  Serial.println(F("******************************"));

  // Initialize the Motor Shield for the wheels
  // also dragon and drum
  AFMS_60.begin();  // create with the default frequency 1.6KHz
  // LED 3 means the first motor shield has been begun
  pixels.setPixelColor(PIXEL_AFMS_60_LED, PIXEL_COLOR_GREEN);
  pixels.show();

  // Initialize the Motor Shield for stepper motor
  AFMS_61.begin();  // create with the default frequency 1.6KHz
  // LED 4 means the second motor shield has been begun
  pixels.setPixelColor(PIXEL_AFMS_61_LED, PIXEL_COLOR_GREEN);
  pixels.show();
  
  //Attach servo motor
  swee.Attach(10);
}

/**************************************************************************/
/*!
    @brief  Constantly poll for new command or response data
*/
/**************************************************************************/
void loop(void)
{

// (SIBA) Add robot arm function
  swee.Update();
  
  /* Wait for new data to arrive */
  uint8_t len = readPacket(&ble, BLE_READPACKET_TIMEOUT);
  if (len == 0) return;

  /* Got a packet! */
  // printHex(packetbuffer, len);

  // Buttons
  if (packetbuffer[1] == 'B') {
    uint8_t buttnum = packetbuffer[2] - '0';
    boolean pressed = packetbuffer[3] - '0';

    // Print button event for debugging
    Serial.print ("Button "); Serial.print(buttnum);
    if (pressed) {
      Serial.println(" pressed");
    } else {
      Serial.println(" released");
    }

    // Take button actions
    doButtonActions(buttnum, pressed);

    // do some stepper action


    Serial.println("Double coil steps");
    myMotor->step(10, FORWARD, DOUBLE);
    myMotor->step(10, BACKWARD, DOUBLE);


  } // end of Button packet
} // end of loop already!


// Depending on the button number, call the appropriate function
//
void doButtonActions(int buttnum, int pressed) {
  switch (buttnum) {
    case 1:
      doButton1Actions(pressed);
      break;
    case 2:
      doButton2Actions(pressed);
      break;
    case 3:
      doButton3Actions(pressed);
      break;
    case 4:
      doButton4Actions(pressed);
      break;
    case 5:
      doButton5Actions(pressed);
      break;
    case 6:
      doButton6Actions(pressed);
      break;
    case 7:
      doButton7Actions(pressed);
      break;
    case 8:
      doButton8Actions(pressed);
      break;
  } // end of selecting based on button number
} // end of do Button


void doButton1Actions(boolean pressed)
{
  if (pressed) {
    doButton1PressedActions();
  } else {
    doButton1ReleasedActions();
  }
}

void doButton2Actions(boolean pressed)
{
  if (pressed) {
    doButton2PressedActions();
  } else {
    doButton2ReleasedActions();
  }
}

void doButton3Actions(boolean pressed)
{
  if (pressed) {
    doButton3PressedActions();
  } else {
    doButton3ReleasedActions();
  }
}

void doButton4Actions(boolean pressed)
{
  if (pressed) {
    doButton4PressedActions();
  } else {
    doButton4ReleasedActions();
  }
}

void doButton5Actions(boolean pressed)
{
  if (pressed) {
    doButton5PressedActions();
  } else {
    doButton5ReleasedActions();
  }
}

void doButton6Actions(boolean pressed)
{
  if (pressed) {
    doButton6PressedActions();
  } else {
    doButton6ReleasedActions();
  }
}

void doButton7Actions(boolean pressed)
{
  if (pressed) {
    doButton7PressedActions();
  } else {
    doButton7ReleasedActions();
  }
}

void doButton8Actions(boolean pressed)
{
  if (pressed) {
    doButton8PressedActions();
  } else {
    doButton8ReleasedActions();
  }
}

void doButton1PressedActions() {

  pixels.setPixelColor(PIXEL_BUTTON_1_LED, PIXEL_COLOR_PRESSED);
  pixels.show();

  // decrease speed of the dragon's wings flapping and the drumming

  if (dragonSpeed >= 5) {
    drumSpeed -= 5;
    dragonSpeed -= 5;
  } else {
    drumSpeed = 0;
    dragonSpeed = 0;
  }
}

void doButton1ReleasedActions() {
  pixels.setPixelColor(PIXEL_BUTTON_1_LED, PIXEL_COLOR_RELEASED);
  pixels.show();
}

void doButton2PressedActions() {
  pixels.setPixelColor(PIXEL_BUTTON_2_LED, PIXEL_COLOR_PRESSED);
  pixels.show();

  // increase speed of the dragon's wings flapping and the drumming

  if (dragonSpeed <= 250) {
    drumSpeed += 5;
    dragonSpeed += 5;
  } else {
    drumSpeed = 255;
    dragonSpeed = 255;
  }
}

void doButton2ReleasedActions() {
  pixels.setPixelColor(PIXEL_BUTTON_2_LED, PIXEL_COLOR_RELEASED);
  pixels.show();
}

void doButton3PressedActions() {
  pixels.setPixelColor(PIXEL_BUTTON_3_LED, PIXEL_COLOR_PRESSED);
  pixels.show();
  noiseOn();
}

void doButton3ReleasedActions() {
  pixels.setPixelColor(PIXEL_BUTTON_3_LED, PIXEL_COLOR_RELEASED);
  pixels.show();
  noiseOff();
}
void doButton4PressedActions() {
  pixels.setPixelColor(PIXEL_BUTTON_4_LED, PIXEL_COLOR_PRESSED);
  pixels.show();
  doStepperAction();
}

void doButton4ReleasedActions() {
  pixels.setPixelColor(PIXEL_BUTTON_4_LED, PIXEL_COLOR_RELEASED);
  pixels.show();
}

void doButton5PressedActions() {
  pixels.setPixelColor(PIXEL_BUTTON_5_LED, PIXEL_COLOR_PRESSED);
  pixels.show();

  goForward();
}

void doButton5ReleasedActions() {
  pixels.setPixelColor(PIXEL_BUTTON_5_LED, PIXEL_COLOR_RELEASED);
  pixels.show();

  stop();
}

void doButton6PressedActions() {
  pixels.setPixelColor(PIXEL_BUTTON_6_LED, PIXEL_COLOR_PRESSED);
  pixels.show();

  goBackward();
}

void doButton6ReleasedActions() {
  pixels.setPixelColor(PIXEL_BUTTON_6_LED, PIXEL_COLOR_RELEASED);
  pixels.show();

  stop();
}

void doButton7PressedActions() {
  pixels.setPixelColor(PIXEL_BUTTON_7_LED, PIXEL_COLOR_PRESSED);
  pixels.show();

  turnLeft();
}

void doButton7ReleasedActions() {
  pixels.setPixelColor(PIXEL_BUTTON_7_LED, PIXEL_COLOR_RELEASED);
  pixels.show();

  stop();
}

void doButton8PressedActions() {
  pixels.setPixelColor(PIXEL_BUTTON_8_LED, PIXEL_COLOR_PRESSED);
  pixels.show();

  turnRight();
}

void doButton8ReleasedActions() {
  pixels.setPixelColor(PIXEL_BUTTON_8_LED, PIXEL_COLOR_RELEASED);
  pixels.show();

  stop();
}

void goForward() {
  Serial.println("goForward");

  leftMotor->setSpeed(255);
  leftMotor->run(FORWARD);
  rightMotor->setSpeed(255);
  rightMotor->run(FORWARD);
}

void goBackward() {
  Serial.println("goBackward");

  leftMotor->setSpeed(255);
  leftMotor->run(BACKWARD);
  rightMotor->setSpeed(255);
  rightMotor->run(BACKWARD);
}

void turnLeft () {
  Serial.println("turnLeft");

  leftMotor->setSpeed(50);
  leftMotor->run(BACKWARD);
  rightMotor->setSpeed(250);
  rightMotor->run(FORWARD);
}

void turnRight() {
  Serial.println("turnRight");

  leftMotor->setSpeed(250);
  leftMotor->run(FORWARD);
  rightMotor->setSpeed(50);
  rightMotor->run(BACKWARD);
}

// stop both motors
void stop() {
  Serial.println("stop");

  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
}


// Go forward for a certain amount of time, stopping
// motors when the time is up
void goForwardTimed(int amount) {
  Serial.print("goForward for ");
  Serial.print(amount);
  Serial.print("milliseconds");
  Serial.println();
  goForward();
  delay (amount); // here we are using the parameter
  stop();
  delay (250);
}


// Function to make the robot turn right
// for a certain amount of time
// This function stops the motor once the
// time is up
// Note that this function takes one parameter,
// namely, the amount of time in millliseconds
// to turn
void turnRightTimed(int amount) { // amount is the parameter
  Serial.print("turnRight for ");
  Serial.print(amount);
  Serial.print("milliseconds");
  Serial.println();

  turnRight();
  delay (amount); // here we are using the parameter
  stop();
  delay (250);
}

void noiseOn() {
  runDragonAndDrum();
}

void noiseOff() {
  runDragonAndDrum();
  drum->run(RELEASE);
  dragon->run(RELEASE);
}

void runDragonAndDrum() {
  // Tell the drum motor and dragon motor to spin
  drum->setSpeed(drumSpeed);
  drum->run(FORWARD);
  dragon->setSpeed(dragonSpeed);
  dragon->run(FORWARD);
  Serial.print("Drum Speed: ");
  Serial.print(drumSpeed);
  Serial.print(" Dragon Speed: ");
  Serial.println(dragonSpeed);
}

void doStepperAction() {
  Serial.println("Interleave coil steps");
  myMotor->step(10, FORWARD, INTERLEAVE);
  myMotor->step(10, BACKWARD, INTERLEAVE);

  Serial.println("Microstep steps");
  myMotor->step(5, FORWARD, MICROSTEP);
  myMotor->step(5, BACKWARD, MICROSTEP);
}

