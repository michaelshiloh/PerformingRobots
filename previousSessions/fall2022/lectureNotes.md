Shortcut to [today's assignment](weeklySchedule.md#todays-assignment)  
Shortcut to [today's lecture](lectureNotes.md#todays-lecture)

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
[Zoom](https://nyu.zoom.us/j/93396476124)

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

### Wednesday September 7

##### Activity
- Finish big motor and external battery

##### Schematics
What is the difference between a schematic and a wiring diagram?

### Monday September 12

##### Discussion

##### Soldering
- Soldering to proto shield
	- Headers
	- Wires

##### Fabrication
- Tools: Drill, screwdrivers, nuts, bolts, and screws, ~ Hot glue gun
- Wooden bases

### Wednesday September 14

##### Mechanical construction
- Don't wear your best clothes
- Put screws/bolts in loose first to get everything in place 
- Then tighten quite firmly, but not with all your strength
	- You want to save some strength for undoing

##### Blink without Delay
Go over the built-in example (File->Examples->Digital->Blink Without Delay)

##### - Neopixels (and libraries)

Some will do pins, some will do wires

### Monday September 19

#### Guest speaker: Tegan McDuffie
- Lecture on dramaturgy

Homework: finish
#### Production
- Attach motors and wheels
	- Special screws
	- Special tool for wheel
- Power Arduino from battery pack
	- Might require attaching coax connector
- Code it to exhibit some personality or emotion only using movement
	but don't share it outside of your team
- When we are done, we will try to guess the personality from the motion

### Wednesday September 21

#### Administration
- The homework must be done by Monday before class starts - I want to build on
	what we have and you must all be ready.
- Note also the reading assignment for Wednesday

#### Presentation
Alpha
#### Discussion
Hessa + Eadin

### Monday September 26

#### Demonstrations:
Show us your robots, we try to guess its personality

#### Parts
- You are responsible for keeping your parts safe. You might want to check out
	a locker
- we will not have time to order replacements
- You each get one charger and 12 batteries
- Label all your parts 
- Put your parts in a box and label the box
- Do not leave your parts out on lab tables. Use the shelves that are
	dedicated to Performing Robots

#### Voltage
- Too low and Arduino resets frequently
- This is one reason we don't want motors using the same power source as
	Arduino

#### Hobby RC
- Review Hobby RC system
- Review our
	[code](https://github.com/michaelshiloh/resourcesForClasses/blob/master/src/arduinoSketches/hobbyRC/minimalMoreChannels/minimalMoreChannels.ino)
- How will we use this?

### Wednesday September 28
#### Discussion (20 minutes)

*The 'Other' Actor* - Louis and Shamsa

#### Hot glue construction (20 minutes)

#### What sort of performance should we make? (20 minutes)

### Wednesday October 5
#### Presentation (20 minutes)
Oliver

#### Discussion (20 minutes)
Dania and Joseph: The Freudian Robot

#### Figure out play

### Monday October 10

#### Today's plan
- Using the nRF24L01 radio for remote control
	- 11:20-12 explain, schematics
	- 12-12:40 build, test
- 12:40-1 break
- 1-1:30 Eadin presentation
- 1:30-2 Hessa presentation

#### the nRF24L01
- Concept
- [Resources](https://github.com/michaelshiloh/resourcesForClasses/tree/master/src/arduinoSketches/nRF24L01)
- Schematic
- Test the radios with
	[this](https://github.com/michaelshiloh/resourcesForClasses/blob/master/src/arduinoSketches/nRF24L01/minimalnRF/minimalnRF.ino)
- [Code](https://github.com/michaelshiloh/resourcesForClasses/blob/master/src/arduinoSketches/nRF24L01/rf24TwoSwitchesTwoLEDs/rf24TwoSwitchesTwoLEDs.ino)
- Working in pairs 
**with someone you have not worked with before (not the robot and not the performance outline)**, 
build it and test
	- Change the address in the code to an unused address. Each pair should put
		their address in Discord so we can tell what's in use


### Wednesday October 12

- Dhabia and Oliver: Thinking something makes it so
- Outlines

### Monday October 24

#### Plan for this week
- Catch up presentations/reading discussions
	- Presentations today
		- From last week: Shamsa
		- Scheduled today: Joseph 
	- Presentations Wednesday
		- Dhabia
	- Reading discussion:
		- none scheduld for this week
- Performance
	- Inside Out
	- I have asked the library to digitize the movie for us so that we can all
		watch it
	- You as a group will write a short play based on the concept of the movie,
		but it does not need to be part of the movie
	- Your play will a robot taking the place of the human
		- The robot playing the human should be more elaborate, and so could
			justify a bigger team of 3 or 4 people, unless two of you wish to take
			on the whole human robot.
		- Depending on how many of you work on the human robot, that leaves 10,
			11, or 12 of you for the other robots so we have either 
			- 5 robots with teams of two (total 10)
			- 6 robots with teams of two (total 12)
			- 5 robots with one team of 3 (total 11)
			- 6 robots with one team of 1 (total 11)

#### Plan for today
- Shamsa
- Finish nRF
	- Add servo motors
- If we have time, start with audio shield

### Wednesday October 26

##### Presentations
- Joseph Hong: Ameca and the advancement of hyper-realistic facial expressions
- Dhabia AlMansoori: Simone Giertz, Michael Reeves, and Mark Rober

### Monday October 31

#### Assignment feedback
- Loved your responses to readings! You all should read them!
- Github resources
	- README.md
	- How to create a new folder
	- Include code and images in README.md 
- Use the `map()` function!
- Robots moving without your instructions?

#### Discussion
"Eight Lessons": Mudi and Yupu lead

#### Performance
Do a class reading of the performance. Critique and discussion.

#### Production
[How to use the Adafruit Music Maker 
shield](https://learn.adafruit.com/adafruit-music-maker-shield-vs1053-mp3-wav-wave-ogg-vorbis-player?view=all)
- Micro SD cards
- Speaker

### Wednesday November 2

#### Homework
- Any issues with the nRF servo potentiometer assignment?
- Soldering the feed through headers to the Music Maker Shield

#### Presentation
Louis

#### Next steps for the play
- How many robots
- Assign teams
- Start building

#### Homework
- IM lab checkout system
- September 12 assignment

### Monday November 7

#### Goal for today
- Music Maker Shield: Problems? Solutions?
- Bad nRF
- Finish play

### Wednesday November 9

#### Today
- Reading discussion (Eckersall), lead by Fatima and Alpha
- Music Maker Shield controlled by nRF: Problems? Solutions?

### Monday November 14

#### Today
- Still working on nRF problems
- Is there anyone who has not yet lead a reading discussion?
- Neopixel matrix (if they have arrived)
- Live demo:
Using the prototyping shield (nRF, neopixel matrix, servo motors, etc.)
- Let's build robots (any remaining time)

### Wednesday November 16

#### Today
- Presentations: 
	- Fatima
	- Dania
- nRF
	- Pair of radios for debugging
- Progress 
	- homework

### Monday November 21

#### Today
- Label your box, hobby RC transmitter, robot, and anything that is outside of
	your box. I will remove anything unlabeled.
- Share robot progress
	- How many servo motors are you using?
- Read through play
- Prototyping shield: go over pin usage again
	- Receiver:
		- nRF: SPI (3) + control (2)
		- Music Maker Shield: SPI (3) + control (4)
		- Neopixel: 1
		- total = 10, not counting servo motors
	- Transmitter:
		- nRF: SPI (3) + control (2)
		- that leaves 15 for control. How shall we do this?
			- Binary system + transmit switch
- Neopixel matrices

### Wednesday November 23

#### Presentation
- Yoki

#### Trip to Museum of the Future

#### Discussion
- What to do about those of you not putting things away
	- Motor
	- Coffin bot
	- Bag from music maker shield
	- Batteries

#### Control board
- Switches user internal PUP and hence common wire is GND not 5V

### Monday November 28, 2022
#### Administration
- [Zoom](https://nyu.zoom.us/j/93396476124)
- Record
- Unmute

#### Review robots!
- Demo driving
- Demo servo motors
- Demo Neo Pixels 

##### Some notes:
- Don't glue batteries
- Don't use tape
- Extend wires for servo motors (3 methods)
- Neopixels
- Brackets

Wednesday: 
- Driving
- All servo motors working (one at a time is fine)

#### Rest of the day
- Distribute Neopixels
- Install electronics in top half
- How to connect the servo motors and neopixels to the Arduino

Design your control panel
- Laser cutter?

### Monday December 5, 2022

#### Review robots!
- Demo driving
- Demo servo motors
- Demo NeoPixels 

#### Review electronics!
- How to connect NeoPixels and servo motors
- How to connect power to NeoPixels and servo motors
- How to connect amplifier to Music Maker Shield

#### Control panel
- Laser cutter
- Hand cut and drill acrylic 
- Plywood

#### Rest of the day
- work

### Wednesday December 7, 2022

#### Today's plan
- Presentation by Yupu
- Legislative days:
	- December 11 (Sunday)-	Classes meet on a Wednesday schedule
	- December 12 (Monday) - Classes meet on a Thursday schedule
	- December 13 (Tuesday)	- Classes meet on a Friday schedule
- Evaluations - do them on your own or take time out on Sunday
- Batteries: 
	- Each Arduino needs 6 AA batteries! 
	- If we are out of holders for 6 batteries, you must combine a two batter
		holder with a 4 battery holder in series. Ask on Discord if you're not
		sure how to do this.
- Control panel
	- I will make them
- Read through play
	- note the number of sound clips

### Sunday 11 December 2022
# todays-lecture
#### Administration
- [Zoom](https://nyu.zoom.us/j/93396476124)
- Record
- Unmute

#### Today's plan

Congratulations! Your robots are the most ambitious and sophisticated this
course has ever built. I have pushed you hard and I've seen how hard most of
you are working. This is appreciated and will be reflected in your grades.

Remember though this is not just a technical course. The readings and
discussions are an equally important component, even though they have been
overshadowed by the robot fabrication work in the last month

Tuesday rehearsal schedule:
- 12 - 2 bring in robots, practice driving, no sound
- 2 - late hopefully get sound system set up, practice

Decisions:
- Do we need to have separate selector switches for servos and NeoPixels?

Work you need to do:
- Strain relief
- Extend servo wires safely
- Check out speakers and find a place to put them
- Label and then charge all your batteries


Work I need to do:
- Build control panels - who is available to help?
- Keep power bank turned on

#### Clean up!

- I need back all your spare Arduinos, batteries, motors, Music Maker Shields,
	wheels, hubs, SD cards, nRF radios, and anything else that you are not using
	in your robots. Please clean out your boxes and put all the parts that you
	don't need on the table in the front of the classroom (where I sit).
- I have an update regarding power banks: we have for checkout power banks
	which do not switch off. I want you each to check out one of these for the
	Arduinos on your robots. Your control panel will still operate on the power
	bank which I gave you. If I gave you two power banks, please return one of
	them.
- Some of you are using AA batteries for the Arduinos on your robot. You may
	continue to do so. Label each battery and charge them. Return any you are
	not using. In this case you do not need to check out the power bank for your
	robot.
- In class yesterday we decided to skip the music maker shield and instead
	each of you will speak for your robot through a microphone. I need back the
	Music Maker Shields from everyone except for Oliver and Hessa 
- Each of you is still using 6 rechargeable batteries for your hobby RC
	transmitter. You should keep in your box the charger for these batteries.
	The charger and each battery must be labeled. 
- Since most of you are not using the Music Maker Shield, you should remove
	this from your code. In particular, remove the libraries related to the
	Music Maker Shield which should give you more memory:

````
#include <Adafruit_VS1053.h>
#include <SD.h>
````



