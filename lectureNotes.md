Shortcut to [today's assignment](#todays-assignment)  
Shortcut to [today's lecture](#todays-lecture)

## New York University Abu Dhabi  
## Interactive Media Program
## Course title: Performing Robots
Course number: IM-UH 2117  

Credit Hours: 4     

Prerequisites: None     

Session: Fall 2023       

Course website:
[https://github.com/michaelshiloh/PerformingRobots](https://github.com/michaelshiloh/PerformingRobots)  

Instructor: Michael Shiloh mshiloh@nyu.edu   

Office hours: If you want to meet schedule an appointment [here](https://calendly.com/michaelshiloh/office_hours)

Meeting times:    
- 2:10-4:50 Monday     
- 2:10-3:25 Wednesday     

Class location: C3-029 (IM Lab)


This is subject to change

This document: Lecture Notes

### Wednesday August 30

#### Administration
- I expect you to bring a notebook to class and to take notes
- I expect you to be on time
- I expect you to participate by thinking, discussing, and making

#### In-class activity

Download and install Arduino from [here](https://www.arduino.cc/en/software)

#### What is this class about
- What are robots?
- What is performance?

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
  - Be on time
  - Bring a notebook to class to take notes
  - Be present and participate in class by thinking, discussing, and making
  - Be experimental: try things you don't know
  - No electronic distractions
  - Be proactive: Communicate with me regarding difficulties, problems, illness, etc. Don't wait until the last minute when I can't help you
  -  Allow lots of time for homework as physical construction
  and debugging circuits and programs can be very time consuming, and your
  ability to estimate how long something should take is very likely wrong
  unless you've done something very much like this before

- Who am I?
- Who are you?
	- Have you used Arduino before?

### Monday 4 Sept 2023
#### Today
- Accounts
    - Review Github?
- Arduino, motors, external power supplies

##### Discord

Please join the IM Discord server. Use it for asking all but personal private
questions

##### Github
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

### Next

##### Arduino!


The built-in examples are a great resource, and there are tutorials for each
one on the Arduino [website](https://www.arduino.cc/) (Documentation ->
Built-in Examples). Let's review these:

The basics
- `digitalWrite()` to turn something on and off (such as an LED)
- `digitalRead()` to read a digital sensor (such as a switch)
In general
- Outputs go with actuators and `digitalWrite()`
- Inputs go with sensors and `digitalRead()`

##### Motors

To control a motor, we need an intermediate device called a motor driver. Our
particular motor driver is based on the L298. To find out how we use it, we
simply Google "L298 Arduino".
[Here](https://howtomechatronics.com/tutorials/arduino/arduino-dc-motor-control-tutorial-l298n-pwm-h-bridge/) is the first thing that showed up for me. The point here is that many of the components we use are quite generic and there is a lot of information on using components with Arduino.

Code: 
````
void setup() {
  // Pins 2 and 3 are connected to In1 and In2 respectively
  // of the L298 motor driver
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  // make the motor turn in one direction
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(5000); // let it turn for 5 seconds

  // now reverse direction
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  delay(5000);
}
````

##### Some more Arduino programming concepts
###### `AnalogWrite()`

###### Conditionals
- if()
- if() ... else

Example 

````
/*
  Demonstrate the use of the if ... else construct
*/

int led = 13;
int otherLED = 7;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(otherLED, OUTPUT);
}

int counter = 0; // create a variable called "counter"

void loop() {
  counter = counter + 1;

  if (counter > 27000) {
		// After awhile, turn off the other LED and turn on the pin 13 LED
    digitalWrite(otherLED, LOW);  
    digitalWrite(led, HIGH);   
  } else {   
    digitalWrite(otherLED, HIGH);  
  }

}
````

Loops
- `while()`
- `for()`

Arduino reference

##### Schematics
What is the difference between a schematic and a wiring diagram?

### Wednesday 6 Sept 2023
##### todays-lecture

#### Administration
- Attendance
  
#### Today
- Review more Arduino 
- Homework: build a robot 1m height minimum
- Construction techniques

##### Arduino review

See above

##### Construction techniques

Metric vs. Imperial dimensions

Holding things together 

Screws vs. bolts
- Screws cut their own threads e.g. in wood
- Bolts go into something that is already threaded e.g. a nut or a threaded
  hole
- Don't force a bolt into a threaded hole. It should go in smoothly. If it
  doesn't it's either the wrong size or it's not straight

Holes
- Through holes for screws or bolts or rods to fit **through**
- Pilot holes are used for screws that will cut their own threads so they
  should be a little smaller than the screw (depends on the strength of the
  material etc., trial and error are sometimes required)
- Threaded holes (something a bolt will fit)

Bolt or screw head patterns
- Slotted
- Phillips
- Allen or hex (metric, imperial)
- Torx

General advice
- Always use the largest screwdriver that fits the screw properly. Using a
  smaller screwdriver can damage the screw, the screwdriver, or both
- When there are multiple screws in something, first put them all in place
  loosly, and
  then tighten after all are in place
- Tighten screws quite snugly but not with all your strength (so you always
  have a bit more strength to undo it)
- Ideally, use the largest screw that fits the hole, but sometimes, if the
  holes don't line up, you can use smaller screws to get a bit of wiggle room.
  Or you can enlarge one of the holes so it lines up with the other.
- Avoid the use of glue or tape on plastic parts. Hot glue is great for
  cardboard and wood, less so on plastic and really bad on metal. Try to
  design parts that attach with screws or nuts and bolts; that's much more
  reliable and they can be removed and reattached easily

Your robot base:
- Wood base
    - What size? What shape?
- Brackets for motors
    - The screws that come with the motor bracket are the wrong size. Give
      them to me (separate the M3 and M4 sizes)
    - Mount them so you can access the wheels
    - Use the correct screws (M4 x 6) 
    - Use the correct screwdriver
- Mount the bracket to the base first, otherwise you can't access the screws
  that hold the bracket to the base
- Mount the wheel to the hub 
    - M4, something short but long enough to go through the hub and the
      wheel and a nut
- Mount the tire on the wheel
- mount the hub to the motor
    - Because the wheel is turning it will constantly be trying to get loose.
    - There are two Allen screws. Put one against the flat part of the motor
      shaft.
    - Tighten the Allen screws really tightly. 
    - **Return the Allen wrench to the container**
- Get the base moving reliably, and then build the body
- Make sure that you can easily access 
    - Arduino
    - Battery
    - Wheels (you will probably have to tighten or replace wheels)

Design for ease of maintenance, modification, and repair
- Always assume that you will have to take things apart many times, either
  because you changed your mind, or you discovered that something isn't going
  to fit, or you forgot to put something on, or it broke, or so many other
  things. Always design for your future self who is going to have to modify,
  repair, and maintain what you make. 
- If you put the Arduino and battery on the bottom, it will be very awkward to
  access them. But the motor wires are short: Learn how to solder longer wires
  on the motors
- Always make wires longer than you need
- Whenever you run wires around, use strain relief. Where are the motor wires
  most likely to break? Right where they go into the motor, and you most
  likely can not repair that. Motor wires are delicate, so you must protect
  them so that if the wires are yanked, that yank is not transmitted to the
  motor.
- Don't use metal screws to attach your Arduino or H-Bridge to the base, as
  they may create a short circuit. Hot glue is OK for this and can easily be
  removed.
- Heavy things like the battery pack can be attached with zip ties.
- Always leave more room than you think you'll need


shopping list
- 2mm T-handle Allen wrench
- m4 x 10 socket head cap screw
- T-handle Allen wrench to fit m4 x 10 socket head cap screw

