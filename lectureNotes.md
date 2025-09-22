Shortcut to [today's assignment](homework.md#todays-assignment)  
Shortcut to [today's lecture](lectureNotes.md#todays-lecture)  
Shortcut to [play
script](https://docs.google.com/document/d/1j0KADb83ufT4OnbhTfyRpN-7AbmNvH17S0KhKeWV_Zc/edit?tab=t.0)  

#### New York University Abu Dhabi  
#### Interactive Media Program

* Course Information
    * Course Code and Number: IM-UH 3117  
    * Course Title: Performing Robots
    * Credit Hours: 4     
    * This is a 14 week course consisting of fourteen 75 minute meetings and
      fourteen 150 minute meetings
    * Instructional time requirements are met by the scheduled meeting times
    * Class location: C3-029 (IM Lab in the Art Center)
    * Prerequisites: IM-UH 1010 or INTM-SHU 101 Interaction Lab or IMNY-UT 101 Creative Computing or DM-UY 1133 Creative Coding
* This course counts toward the following NYUAD degree requirements:
    * Majors > Interactive Media
    * Majors > Interactive Media > Physical Computing 
    * Minors > Interactive Media
* Faculty Details
    * Professor: Michael Shiloh mshiloh@nyu.edu   
    * Office hours: Schedule an appointment [here](https://calendly.com/michaelshiloh/office_hours)
    * Office phone number: 02-628-5185
    * Office location: C3-156

* Session: Fall 2025       
* Meeting times:    
	- 3:20-4:35 Tuesday
	- 3:20-6:00 Thursday

* Course website: [https://github.com/michaelshiloh/PerformingRobots](https://github.com/michaelshiloh/PerformingRobots)  

This document: Lecture Notes

### Tuesday August 26 Week 1

#### Administration
- I'll be gone next week!
- Apply to be a [Lab Assistant](https://app.joinhandshake.com/emp/jobs/10154995)

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
    - [This class in 2023](https://drive.google.com/file/d/1WoT0_J1sPGSjmjJODrpIFxpetJMYGRMR/view?usp=sharing)

- What is this class about?
- [weekly schedule](weeklySchedule.md)
- [Syllabus](syllabus.md)

**Be prepared to work hard in this class!**

- If you have never built mechanisms, then the model that you have in your
  head of how something should work will likely be very wrong. As a result,
  what worked perfectly in your head in theory will be very likely to fail in
  practice.
- Expect to rebuild the same thing many times until it works. 
- Even after you get things working, expect them to break as your robot moves
  around
- Expect that your estimates of how long something should take to be very
  wrong
- A robot is a complex system consisting of many different sub-systems.
  While each sub-system might work perfectly by themselves, when they are
  integrated into a single system unexpected interactions may (will) cause
  unexpected problems.

- Introductions
	- What is your creative passion?
	- What is your experience with theater?
	- Have you built robots before?
    - What experience do you have with construction and mechatronics?
    - What experience do you have with hand and power tools?

Homework
- See shortcut above

### Thursday August 28
- Arduino, solderless breadboard, switch
- L298 Motor Driver with external battery and large motor

#### Administration
- I'll be gone next week!
- Apply to be a [Lab Assistant](https://app.joinhandshake.com/emp/jobs/10154995)
- One seat open in Communications Lab


#### Very quick review of Arduino

#### Very quick review of switch and LED on solderless breadboard
- Use built-in pullup resistor for switch. This means switch pulls `HIGH`.

#### L298 Motor Driver with external battery and large motor

To control a large motor, 
we need an intermediate device called a motor driver. Our
particular motor driver is based on the L298. To find out how we use it, we
simply Google "L298 Arduino".
[Here](https://howtomechatronics.com/tutorials/arduino/arduino-dc-motor-control-tutorial-l298n-pwm-h-bridge/)
is the first thing that showed up for me. The point here is that many of the
components we use are quite generic and there is a lot of information on using
components with Arduino, but we can not follow the instructions blindly. We do
need to understand how it works.

**Warning** there is an error in the schematic under *Arduino and L298N Motor
Driver*. Can you spot the problem? Hint: Look at the schematic under *Arduino
Robot Car Control using L298N Motor Driver* and see if you can find the added
connection that was missing.

##### Code
Before you look at the code here, think about the circuit.
- `EN` needs to be `HIGH` in order to turn on the motor driver
- IN1 and IN2 need to be opposite (if one is `HIGH` then the other should be
  `LOW`) in order to make the motor turn
- Can you think of how to do this? (Hint: you can do this with 4 lines of code
  in `setup()` function and an empty `loop()` function)


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

### Thursday September 11
- Play theme and cast
- Hobby RC concepts

### Tuesday September 16
Play feedback

### Thursday September 18
- Soldering
- IM Lab policies
- Robot base: add H-bridge, Arduino

#### Soldering
- Wire to wire (stranded-stranded)

#### Robot base: add H-bridge, Arduino
- Mounting the Arduino
- Mounting the H-bridge
- Mounting the battery

##### todays-lecture
### Tuesday September 23
- Homework
- Soldering
- L298 interface board and Arduino shield
- Robot base
- Remote control

###### Homework
- [Play](https://docs.google.com/document/d/1j0KADb83ufT4OnbhTfyRpN-7AbmNvH17S0KhKeWV_Zc/edit?tab=t.0) outline
- [Research presentations](https://docs.google.com/spreadsheets/d/1H67fPcgNpJAw_h9IF7Uh4UINfpykP3S3smrm_njblvk/edit?usp=sharing)

##### Soldering
- Heat shrink tubing
- Wire to board (stranded)
- Pins and headers sockets

##### L298 Breakout Board to the Hobby RC and Motor Controller shield
- Wire mapping
- Header pins and sockets must be on the correct side
- Header pins must be straight
- Excellent soldering
- No short circuits

2. Connect the L298 Breakout Board to the Hobby RC and Motor Controller shield
following the table below:

| L298 Pin | Arduino Pin | Wire Color |
| --- | --- | ----- |
| EN1 | 9 | Yellow |
| IN1 | 8 | Blue |
| IN2 | 7 | Blue |
| IN3 | 10 | Green |
| IN4 | 12 | Green |
| EN2 | 11 | White |
| GND | GND | Black |

Videos:
- [Solder pins according to board](https://youtu.be/TmrvE1iV0zE)
- [Soldering header socket to L298 Breakout Board](https://youtu.be/Eat3gU4fdVc)
- Soldering wires between L298 Breakout Board and Hobby RC and Motor Controller Shield,
  [part 1](https://youtu.be/473tP4C34UU) and [part
  2](https://youtu.be/3yuinKMAYRI)

###### Robot base
- Wiring it all up
- Battery needs 5v cable

##### Remote control
- Pairing
- Test using
  [code](https://github.com/michaelshiloh/resourcesForClasses/blob/master/src/arduinoSketches/hobbyRC/minimalMoreChannels/minimalMoreChannels.ino)
