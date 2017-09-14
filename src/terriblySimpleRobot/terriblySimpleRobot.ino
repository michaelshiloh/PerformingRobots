/*
  Terribly simple robot
  Based on Adafruit DCMotorTest - thanks Adafruit!

  11 Sept 2017 - Michael Shiloh - Program creation
  12 Sept 2017 - Michael Shiloh - Added comments explaining
                                  what some of the functions do
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor * rightMotor = AFMS.getMotor(1);
Adafruit_DCMotor * leftMotor = AFMS.getMotor(2);

void setup() {
  Serial.begin(9600);    // set up Serial library at 9600 bps

  AFMS.begin();  // create with the default frequency 1.6KHz

  // Try to do a square:
  goForward();
  delay (2000); // amount of time to go forward
  stop();       // what it says
  delay (250);  // let motors actually stop

  turnRight(300); // turn right for this much time

  goForward();
  delay (2000);
  stop();
  delay (250);

  turnRight(300); // 300 is the argument

  goForward();
  delay (2000);
  stop();
  delay (250);

  turnRight(300);

  goForward();
  delay (2000);
  stop();
  delay (250); // totally unnecessary
}



void loop() {
}

// Function to make the robot go forward
// This function does not stop the motor
// Note that this function takes no parameters
void goForward() {
  Serial.println("goForward");
  leftMotor->setSpeed(150);
  leftMotor->run(FORWARD);
  rightMotor->setSpeed(150);
  rightMotor->run(FORWARD);
}

// stop both motors
void stop() {
  Serial.println("stop");
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
}

// Function to make the robot turn right
// for a certain amount of time
// This function stops the motor once the
// time is up
// Note that this function takes one parameter,
// namely, the amount of time in millliseconds
// to turn
void turnRight(int amount) { // amount is the parameter
  Serial.println("turnRight");
  leftMotor->setSpeed(250);
  leftMotor->run(FORWARD);
  rightMotor->setSpeed(50);
  rightMotor->run(BACKWARD);
  delay (amount); // here we are using the parameter
  stop();
  delay (250);
}

void turnLeft() {
  Serial.println("turnLeft");
  leftMotor->setSpeed(250);
  leftMotor->run(BACKWARD);
  rightMotor->setSpeed(50);
  rightMotor->run(FORWARD);
}

// I used this function at the begining to test the
// motors and confirm that they were turning in the
// right direction, but once I was done I didn't
// need this anymore; however I'm keeping it in here
// (a) as more examples and (b) in case I need to use
// it again
void testRobot() {
  // do a little test:
  // Go forward for a bit
  leftMotor->setSpeed(150);
  leftMotor->run(FORWARD);
  rightMotor->setSpeed(150);
  rightMotor->run(FORWARD);
  delay (500);

  // stop for a moment before changing direction
  // to avoid stressing the motor
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
  delay (250);

  // Go backwards for a bit
  leftMotor->setSpeed(150);
  leftMotor->run(BACKWARD);
  rightMotor->setSpeed(150);
  rightMotor->run(BACKWARD);
  delay (500);

  // and stop.
  // Note that the  comment in the example is wrong:
  // RELEASE turns the motor OFF
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
}

