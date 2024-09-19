Shortcut to [today's assignment](homework.md#todays-assignment)  
Shortcut to [today's lecture](lectureNotes.md#todays-lecture)

## New York University Abu Dhabi  
## Interactive Media Program
## Course title: Performing Robots
Course number: IM-UH 2117  

Credit Hours: 4     

Prerequisites: None     

Session: Fall 2024       

Course website:
[https://github.com/michaelshiloh/PerformingRobots](https://github.com/michaelshiloh/PerformingRobots)  

Instructor: Michael Shiloh mshiloh@nyu.edu   
Support staff: Stefania Avramidi sa8410@nyu.edu

Office hours: Schedule an appointment [here](https://calendly.com/michaelshiloh/office_hours)

Meeting times:    
- 2:10-3:25 Tuesday
- 2:10-4:50 Thursday

Class location: C3-029 (IM Lab)

This is subject to change

This document: Lecture Notes

### Tuesday August 27

#### Administration

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
    - [Last
      year](https://drive.google.com/file/d/1WoT0_J1sPGSjmjJODrpIFxpetJMYGRMR/view?usp=sharing)

- What is this class about?
- [weekly schedule](weeklySchedule.md)
- [Syllabus](syllabus.md)

- Who are we?
- Who are you?
	- Have you used Arduino before?
    - What experience do you have with construction?
    - What experience do you have with hand and power tools?

Homework
- Github
- Discord

### Thursday August 29
#### Today
- Very quick review of Arduino
- Very quick review of switch on solderless breadboard
- L298 Motor Driver with external battery and large motor

#### Lecture

##### Very quick review of Arduino

##### Very quick review of switch and LED on solderless breadboard
- Use built-in pullup resistor for switch. This means switch pulls `HIGH`.

##### L298 Motor Driver with external battery and large motor

To control a large motor, 
we need an intermediate device called a motor driver. Our
particular motor driver is based on the L298. To find out how we use it, we
simply Google "L298 Arduino".
[Here](https://howtomechatronics.com/tutorials/arduino/arduino-dc-motor-control-tutorial-l298n-pwm-h-bridge/)
is the first thing that showed up for me. The point here is that many of the
components we use are quite generic and there is a lot of information on using
components with Arduino, but we can not follow the instructions blindly. We do need to understand how it works.

Sample code, assuming you used these pins: 
```
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
```

### Tuesday September 3
#### Today
- Shields
- Soldering
#### Lecture

##### Shields
- Ready made shields
    - Music Maker Shield
- Prototyping shields
    - No solderless breadboard!
    - What can go wrong?
- Custom shields
    - Servo shield
- Other PCBs

##### Soldering demonstration 
- Wires to boards
    - What can go wrong?
- Music Maker Shield pins
    - What can go wrong?
- NeoPixel Pins
    - What can go wrong?
- Fixing problems

### Thursday September 5
#### Today
- Music Maker Shield
- NeoPixels

##### Music Maker Shield
- [Adafruit Music Maker Shield](https://learn.adafruit.com/adafruit-music-maker-shield-vs1053-mp3-wav-wave-ogg-vorbis-player?view=all)

##### NeoPixels
- [Neopixels](https://learn.adafruit.com/adafruit-neopixel-uberguide/the-magic-of-neopixels)


### Tuesday September 10
#### Today
- Homework
- Performance

### Thursday September 12
#### Today
- Results of vote!
- Presentation schedule!
- Robot Base!

##### Results of vote!
* Which play are we doing?
* Homework for next week: 

1. Choose a partner and a character that you and your partner would like to
   work on
1. Collaborate with entire class (use Discord or create any group you wish)
    to create outline of play collaboratively

##### Presentation schedule!
[here](https://docs.google.com/spreadsheets/d/1s8S0qX6co3bIBSuFY7zDSmBrV4rCpc_IT61iG6xhgfM/edit?gid=0#gid=0)

##### Robot Base

- Motors
- Arduino
- L298 Motor Driver 
- External battery 

How does it drive?

- Wheels 
- Tires
- Hubs
- Steering

How do we build it?

- Wooden base
- Where should the wheels go?
- How does it keep from tipping over?

Construction techniques

- Motor mounting brackets
- Screws vs. Nuts and Bolts
- Working with wood
- Wire management
- Holding down the circuits (Arduino, L298)
- Holding down the battery

### Tuesday September 17
#### Today
- Announcements
- Presentations
- Design workshop

##### Announcements
- Student-lead workshops
    - certificate
- IM Program Gathering
    - Thursday right after class

##### Presentations

[Presentation
schedule](https://docs.google.com/spreadsheets/d/1s8S0qX6co3bIBSuFY7zDSmBrV4rCpc_IT61iG6xhgfM/edit?gid=0#gid=0)

##### Design workshop
(add link here)

#### todays-lecture
### Thursday September 19
#### Today
- Hind presentation
- Build robots!
- L298 board

Time permitting:
- Giant servo motors and external power supply
- Solder other PCBs
