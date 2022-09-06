Shortcut to [today's lecture](#todays-lecture)

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
11:20-2:00 Monday     
12:45-2:00 Wednesday     
Session: Fall 2022       
[Discord](https://discord.gg/mFJ5fqKk)

This is subject to change

This document: Lecture Notes

### Week 1 August 29 and August 31

### Monday August 29 

#### Administration
- Reminder that masks are required at all times indoors except when actively
	eating
- I expect you to bring a notebook to class and to take notes

#### In-class activity

Download and install Arduino from [here](https://www.arduino.cc/en/software)

#### What is this class about
- What are robots?
- What is performance?
- What is Interactive Media?
	- Read *What I want you to know* from
		[here](https://www.wired.com/2013/09/focus-on-people-not-tech-and-other-impt-lessons-for-interaction-design-and-life/)
		in class

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
	- Have you used Arduino before?

#### Do along with me

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

### Wednesday August 31

##### Arduino Programming!


The built-in examples are a great resource, and there are tutorials for each
one on the Arduino [website](https://www.arduino.cc/) (Documentation ->
Built-in Examples). Let's review these:

The basics
- `digitalWrite()` to turn something on and off (such as an LED)
- `digitalRead()` to read a digital sensor (such as a switch)
In general
- Outputs go with actuators and `digitalWrite()`
- Inputs go with sensors and `digitalRead()`

To control a motor, we need an intermediate device called a motor driver. Our
particular motor driver is based on the L298. To find out how we use it, we
simply Google "L298 Arduino". Here is the first thing that showed up for me:

https://create.arduino.cc/projecthub/ryanchan/how-to-use-the-l298n-motor-driver-b124c5

Code: (I forgot to save my sketch so I did this from memory. I'm pretty sure
it's correct):
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

### Week 2 September 5 and 7

### Monday September 5
##### Some more Arduino programming concepts
###### `AnalogWrite()`
Example we developed in class:

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
  analogWrite(3, 50); // go slowly
  delay(5000); // let it turn for 5 seconds

  // digitalWrite(2, LOW);
  analogWrite(3, 195); // faster!
  delay(5000); // let it turn for 5 seconds

  // now reverse direction
  digitalWrite(2, HIGH);
  analogWrite(3, 50); // this will be fast!
  delay(5000);

  analogWrite(3, 230); // now go slowly
  delay(5000);
}
````

###### Conditionals
- if()
- if() ... else

Example we developed in class:

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

##### More motors: Bigger motors and external batteries
(or soldering lesson if we don't find the coax connectors)

### todays-lecture
### Wednesday September 7

##### Schematics

##### Remote control

- Connect a radio receiver to your Arduino and control things remotely!

- Libraries
- How to use `Serial.print()` 
- `analogWrite()` to control the brightness of an LED
