Shortcut to [today's lecture](lectureNotes.md/#todays-lecture)

## New York University Abu Dhabi  
## Interactive Media Program
## Course title: Performing Robots
Course number: IM-UH 2117  
Credit Hours: 4     
Prerequisites: None     

Course website:
[https://github.com/michaelshiloh/PerformingRobots](https://github.com/michaelshiloh/PerformingRobots)  
Instructor: Michael Shiloh mshiloh@nyu.edu
Office hours: By appointment    
Meeting times:    
10:25-11:40 M     
9-11:40 W     
Session: Fall 2021    
[Zoom](https://nyu.zoom.us/j/92630541872)

This is subject to change

This document: Lecture Notes

### Week 1 August 30 and September 1

### August 30 

Administration
- Record 

Introduction

- Watch some videos
	- [Welcome to Duloc](https://www.youtube.com/watch?v=X81AoBcVnaA)
	- [Survival Research Labs](https://youtu.be/aZwkvM4BzN4?t=302)
	- [Bot and Dolly](https://youtu.be/lX6JcybgDFo?t=132)
	- [Oriza Hirata](https://youtu.be/CWnnqObk1qM)
	- [Robotic Church](https://vimeo.com/114296519#t=120s)

- What is this class about?
- [weekly schedule](weeklySchedule.md)
- [Syllabus](syllabus.md)
- Summary:
  -  Be present and participate in class
  -  No electronic distractions
  -  Be proactive: Communicate with me regarding difficulties, problems, illness, etc.
  -  Allow lots of time for homework as physical construction
  and debugging circuits and programs can be very time consuming.
- Who am I?
- Who are you?

Getting Ready

- Collecting stuff
- Cardboard
- Space
- Hot glue gun
- Soldering iron
- Rubbing Alcohol

Do along with me

- Discord
- Github
- Arduino

**Github**
- What is Github?
- Difference between an account and a repository
- Follow along with me and create an account
- Instructions for this are
[here](https://github.com/michaelshiloh/resourcesForClasses#github-resources).

Please use your name for your account name so that I 
can more easily recognize it. 
If you don't want to use your name for privacy reasons, 
please choose an alias that I can recognize as you.

Name your repository "Performing Robots"

### September 1

Administration
- Record 
- Commitments
- Is anyone using the Github desktop or command line tools?

Github review (if necessary)

- Edit your README.md file
	- What is README.md?
	- What is .md?
- Simple Markdown 
	- **Bold**
	- Paragraphs must be separated by a blank line
	- Inserting images: ![](media/eye-calipers.jpg)
	- Always remember to commit your changes!
	- More [here](https://github.com/michaelshiloh/resourcesForClasses#github-resources).

Arduino Programming!

The built-in examples are a great resource, and there are tutorials for each
one on the Arduino [website](https://www.arduino.cc/) (Documentation ->
Built-in Examples). Let's review these:

The basics
- `digitalWrite()` to turn something on and off (such as an LED)
- `digitalRead()` to read a digital sensor (such as a switch)
- How to use `Serial.print()` 
- `analogWrite()` to control the brightness of an LED
- `analogRead()` to read an analog sensor (such as a light sensor)

Schematics

Conditionals
- if()
- if() ... else

Loops
- `while()`
- `for()`

In-class exercise:
- Work in pairs to come up with a system with two buttons and two LEDs that
	will do different things depending on how many buttons are pressed

### September 6

Administration
- Record 
- Any questions about last week's exercise with the buttons and LEDs?

#### Soldering 

##### Preparation

- Get solder ready (unwrap plastic)
- Remove plastic cover from soldering iron
- **Keep it on the silicon mat!!**
- Make sure it can't roll off the table
- Plug in iron
- Set temperature to 330
- Careful of the soldering iron tip
- Tinning the tip

##### Exercise: Wire to wire

- Wire (don't use red or black)
- Wire cutters/strippers
- Twist tightly
- Use something to hold the wire (cutters, brick)
- Soldering iron below, solder from above
	- Heat rises, liquid flows down
- OK to reheat if you don't like the way it looks
- Practice a few more times

##### Real work: Wire to motor

- Strip wire
- Tin wire
- Note that copper tabs are extremely delicate
	- Avoid twisting and bending the wire once you solder to the tabs
- Tin copper tabs
- Trim wire to length of tab
- Put wire on tab and reheat to get the two solders to melt to each other
- **Strain relief**
- Testing motors

### September 8

Administration
- Record 
- Presentations
- Testing motors

##### Test Arduino
- IDE
- Arduino + USB cable
- Blink

##### Arduino review (in-class exercise)
Work in pairs
- LEDs + 1K resistors
- Switches + 10K resistors
- Questions? 

##### Prepare H-bridge

- How to use a screwdriver
	- Especially if the size is wrong or the screws are poor quality
- Gently pry open 
- Prepare battery black wire
- Insert battery wires, carefully observing polarity
	- Red is + 
	- Black is - GND 
- Attach motor wires (polarity doesn't matter)
- Attach jumpers for H-bridge
- Code
- Enjoy

Here are the two programs we used in class to test the motor

````
// Simple program to demonstrate turning a DC motor on and off
// Using the L298 H-bridge module

// Pin connections
const int in1Pin = 7;
const int in2Pin = 6;
const int in3Pin = 5;
const int in4Pin = 4;

void setup() {
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
}

void loop() {

  // The motor turns when its inputs have opposite values
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, LOW);

  delay(1000);

  // The motor stops when they have the same value
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, HIGH);

  delay(1000);

}
````

````
// Simple program to demonstrate controlling the speed and direction
// of a DC motor using the L298 H-bridge module

// Pin connections
const int in1Pin = 7;
const int in2Pin = 6; // PWM pin!
const int in3Pin = 5; // PWM pin!
const int in4Pin = 4;

void setup() {
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
}

void loop() {

  // By making in3 go high we activate the motor. By
  // using analogWrite() we control how long the pulse
  // is high and hence the speed.
  analogWrite(in3Pin, 75);
  digitalWrite(in4Pin, LOW);

  delay(1000);

  // To reverse the direction of rotation, in3 must be low
  // and in4 must be high.
  // We can still control the speed, but now it is the low part of the PWM
  // pulse that makes the motor go. To get a similar speed,
  // we must subtract 75 from 255 (the highest value)
  // to make the low part of the pulse identical to
  // the high part of the pulse when we rotated in the opposite direction
  analogWrite(in3Pin, 255 - 75);
  digitalWrite(in4Pin, HIGH);

  delay(1000);

}
````

### September 12

#### Administration

- Record 
- Any problems with the second motor (soldering, H-bridge)?

#### Presentation

- Discussion of presentation

#### What are we doing?

- What is a performance?
- What is a robot?
- What can we realistically build?

### September 14

#### Administration

- Record 

#### More Arduino practice

##### First of all, where do we learn about the H-bridge?

- There is no documentation on the module
- How do we know what to look for?
	- Does the big IC have a name?
- Generic
	- They all *seem* to be the same (although there is no guarantee) 
- Do a quick search for L-298 driver or L-298 H-bridge
- In-class exercise: draw a schematic for the Arduino + H-bridge + battery +
	motor

##### Switches, potentiometers, and the H-bridge

- Switches and two motors
	- Schematic
- Potentiometer to control speed
- Potentiometer to control speed and direction

#### Construction techniques

##### Prepare

- Hot glue gun
- Hot glue sticks
- Cardboard
- Scissors
- Found objects

##### Techniques

- Precision
- Preventing collapse
	- Braces
- Rigidity
	- T profile
		- Braces?
	- I profile
		- Braces?

### September 20

#### Administration

- Record 
- A message from the Wellness Department
	- "The Wellness Department is intentionally making an effort to extend its
		reach to students.  Instead of having students come to us to seek wellness
		or lessons on wellness and holistic health we want to get out more across
		campus to meet students where they live and go to class.  

		We realize your day is busy and your life is busy so we've developed a
		space in A-5-A for you to gather some wellness related information.  We're
		also making plans for outreach across the residential spaces in the form
		of evening sessions which will involve simple tactile artistic work that
		could take many shapes and be in different mediums.

		One other initiative is what we're doing with Professor Shiloh that you're
		going to be part of in class.  We simply want to expose you to what
		meditation is like by using the Headspace app for a few minutes during
		class.  It is a guided meditation exercise that has been shown to help
		people experience stress less, focus more and even sleep better.
	- Logistics:
		- 5 minute exercise at the beginning of class on Wednesday
		- Please be in a quiet place where you won't be disturbed and feel
			comfortable sitting with your eyes closed

#### Homework sharing and critique

- Is your robot expressive? Can it create an emotional response in the
	audience?
- How would you use this robot in a performance?
- What difficulties do you anticipate?
- What changes might you make?

### todays-lecture
### September 22

#### Administration

- Record 
- Jack and Ume Introductions (at end of class, 11:30)
- Zhiyang's presentation

#### Meditation

#### More things from your kit:

- Servo motor
- LiPo battery and booster

#### Let's make the robots more mobile

- Getting rid of the USB cable
	- Power the Arduino with LiPo battery, USB adapter, and switch
- Powering the motor driver
	- Remember our discussion last week of the +5V connection

#### Getting rid of `delay()`

Adafruit Multitasking
[Tutorial](https://learn.adafruit.com/multi-tasking-the-arduino-part-1?view=all)

#### A better way to handle sequences: State Machines

Suppose we want to cycle through different behaviors when a button is pushed. 
How might we do this?
- State Machine

Simple
[example](https://github.com/michaelshiloh/resourcesForClasses/tree/master/src/arduinoSketches/stateMachines/simpleArduinoStateMachine)
which does nothing but shows how to implement a state machine
either with a bunch of `if()` statements or with a `switch()` statement

[Example](https://github.com/michaelshiloh/resourcesForClasses/tree/master/src/arduinoSketches/noDelay/melodyBlinkStateMachine)
of a state machine which blinks LEDs and plays a melody
all without using the `delay()` function!

#### Edge triggering

````

/* 
 *  Using state variables to create a toggle effect
 */
 
const int BUTTONPIN = 3;
const int LEDPIN = LED_BUILTIN;

void setup() {
  pinMode(LEDPIN, OUTPUT);
}

// state variables
int lastcurrentButtonState = LOW;
int ledState = LOW;

void loop() {
  int currentButtonState = digitalRead(BUTTONPIN);

  if ((lastcurrentButtonState == LOW) && (currentButtonState == HIGH)) {
    
    // Aha! the button has been pressed; time to toggle the LED
    ledState = 1 - ledState; // clever trick to toggle the state

    // update the LED itself
    digitalWrite(LEDPIN, ledState);

    // Wait for switch to stop bouncing
    delay(10);
  }

  // Update the last button state
  lastcurrentButtonState = currentButtonState;
}
````

#### Digital Multi Meter

- Battery
- Measuring resistance 
	- Resistor
	- Motor
	- Yourself
	- **Component must not be part of a circuit**
- Measuring continuity
	- **Circuit must not be powered**
	- Solder connection
	- Connection to pin of an Arduino
	- Connection to pin of a switch
- Measuring voltage:
	- Battery
	- Arduino 5V
	- Arduino output
		- Staying at one level
		- Blinking
		- Connecting to breadboard
	- Testing LEDs

#### More soldering and circuit building skills

##### Neopixel matrix 

How would you approach this?
