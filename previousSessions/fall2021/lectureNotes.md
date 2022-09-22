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
	- [Here](https://handsontec.com/dataspecs/module/L298N%20Motor%20Driver.pdf) is an example datasheet
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

### September 22

#### Administration

- Record 
- Jack and Ume Introductions (at end of class, 11:30)
- Zhiyang's presentation pushed to next week (we'll have two on one day)
- Pick up second Arduino and breadboard before next Wednesday

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
	- Switch
	- Arduino output
		- Staying at one level
		- Blinking
		- Connecting to breadboard
	- Testing LEDs

### September 27

#### Administration

- Record 
- Did you all get your second Arduino and breadboard?
- Feedback regarding meditation: please email me

##### NeoPixel matrix 

For maximum flexibility, we will solder header pins to the Neopixel matrix
and the solder wires to a header socket

**Remember to remove the cap from your soldering iron before you plug it in**

- Carefully cut off 3 header pins (can cut between pins)
- Solder header pins to module
	- Header pins on opposite side of LEDs
	- Make sure the pins are pushed flush against the board
	- Make sure they are straight
- Carefully cut off 3 header sockets (can not cut between sockets, 
must sacrifice one socket)
- Solder wires to socket
	- **Stranded wire**
	- Ideally, red for 5V, black for GND, any other color for control signal
	- Tin socket pins and wire
	- Trim wire down to length of solder tail on socket (i.e. tiny)
	- Place wire on socket pin and reheat to melt the two solders together
- Solder a small piece of **solid core** wire to the other end of the stranded
	wire to make it easy to stick into breadboard
- Twist wires together or get some zip ties from IM lab

**Programming**

Adafruit NeoPixel
[Uberguide](https://learn.adafruit.com/adafruit-neopixel-uberguide?view=all)

- Install Adafruit NeoPixel library 
	- Sketch -> Include Library -> Manage Libraries
	- Search for Adafruit NeoPixel
- Open example
	- File -> Examples -> Adafruit NeoPixel -> Strandtest
	- Change pin number 
	- Change LED_PIN and LED_COUNT as necessary
- Might look at Adafruit NeoMatrix library, I've not yet tried it

### September 29

##### Meditation

##### Administration

- Record 

##### Wireless remote control with nRF24L01 radio modules

- Common example of a
	[tutorial](https://lastminuteengineers.com/nrf24l01-arduino-wireless-communication/) which is widely duplicated on the web
	- Unfortunately many tutorials on the web are copies of another
	- Unfortunately some of them have an error
- We will use this [example](https://github.com/michaelshiloh/resourcesForClasses/tree/master/src/arduinoSketches/nRF24L01)
which includes a schematic


### October 4

##### Administration
- Record 

##### Servo motors

##### Power considerations

Let's try an experiment (perhaps just a thought experiment): 

- Connect the NeoPixel array
- Connect all 3 servo motors
- Connect all 6 DC gearmotors
- Write a program to turn everything on at full speed 

What might be happening?

- 64 LEDs consume quite a bit of **current**
- All motors consume quite a bit of **current**
- Whenever **current** flows through a **resistance** there is a **voltage**
	drop (Ohm's law)
- Everything, even wire, has some resistance
- Therefore, when the motors and the LEDs are on, there could be a substantial
	**voltage** loss in the wires, connectors, etc.
- If the **voltage** starts off at the PowerBoost at 5V, by the time it gets to
	the Arduino there may in fact be less than 5V
- If the **voltage** at the Arduino is below a certain value (maybe somewhere
	around 3V) the Arduino will shut down

What's the solution?

- Provide two separate power supplies:
	- One for Arduino
	- One for all motors and LEDs
- That's one reason you have two PowerBoosts and LiPo batteries

##### Digital Multi Meter

**Remember that you must make a very firm connection!!!**

- Measuring resistance 
	- Resistor
	- Motor
	- Yourself
	- **Component must not be part of a circuit**
- Measuring continuity
	- **Circuit must not be powered**
	- Solder connection
	- Connection to pin of an Arduino
		- Connecting to breadboard, Arduino, and other headers
			- Alligator cable (get two)
	- Connection to pin of a switch
- Measuring voltage:
	- Battery
	- Arduino 5V
	- Switch
	- Arduino output
		- Staying at one level
		- Blinking
	- Testing LEDs


### October 4

#### Meditation

#### Administration
- Record 

#### Working with binary numbers

- Binary numbers

````
decimal binary		hexadecimal
1       0b00000001	0x01
2       0b00000010	0x02
3       0b00000011	0x03
4       0b00000100	0x04
5       0b00000101	0x05
6       0b00000110	0x06
7       0b00000111	0x07
8       0b00001000	0x08
9       0b00001001	0x09
10      0b00001010	0x0A
11      0b00001011	0x0B
12      0b00001100	0x0C
13      0b00001101	0x0D
14      0b00001110	0x0E
15      0b00001111	0x0F
````

- Bits
- Expressing information as bits
- Manipulating bits
	- Shifting
	- bitwise OR
	- bitwise AND
	- testing for equality
		- individual bits
		- entire value

#### Sending multiple values

- The RF24 class [reference page](https://nrf24.github.io/RF24/classRF24.html)
- Is it really necessary? How many bits are there in an int?
	- Not enough? Use a long!
	- But what about this (found in `read()` in the reference page):
	"The length of data read is usually the next available payload's length"

Example that we developed in class for sending two bytes, now tested:
- [Transmitter](https://github.com/michaelshiloh/resourcesForClasses/blob/master/src/arduinoSketches/nRF24L01/rf24XmitTwoBytes/rf24XmitTwoBytes.ino)
- [Receiver](https://github.com/michaelshiloh/resourcesForClasses/blob/master/src/arduinoSketches/nRF24L01/rf24RcvrTwoBytes/rf24RcvrTwoBytes.ino)

### October 11

#### Administration
- Record 

#### Using Github for backup
- Make a separate folder for intermediate work (tests, experiments, etc.)
- Make an entirely new repository and mark it *private*

### October 13

- Meditate
- Record 
- Let's see your amazing projects!

### October 25

#### Administration

- Cameras on please, unless you discussed with me reasons why not
- Record 
- Welcome back from break! I hope you all had a great time
- Who was having power problems? I have some ideas I want you to try out

#### Presentation

Zhiyang: Analysis of Interactive Autonomous Robots in the Context of Theatre

#### Discussion

Knowing what you know now from designing, constructing, and programming your
robots, discuss our answers to the homework assignment:

Choose a short scene from a play and a character in that scene, and consider
how you would make a robot actor to perform that scene. Any spoken words will
come from a human or a computer, not from your actor.

- How would you build the actor?
- What technical features will the actor need?
- How will you construct the actor to create the role?
- How will you decorate or dress the actor for best effect?
- What sequence of moves or other actions will you give your actor so that they can best play the part?

### October 27

#### Start
- Meditate

#### Admin
- What can I do to hear those of you who never (or rarely) speak up in class?
- Record 
- End of Semester show will be Tuesday December 14th 6-9pm

#### Presentation

Jung Soo: The Machine as Artist: An Introduction

#### Homework

Finish showing and discussing Monday's homework assignments

#### Demonstration: solder your circuit on a prototyping shield

##### Why
- Solve problems with the solderless breadboard
- Unfortunately, we lose the flexibility that comes with the solderless
	breadboard

##### How

First, consider what the board needs

Let's start with the transmitter. 
Let's see if we can leave room for  as many inputs as possible to
allow the for the most ways to control a robot. When we build the circuit
we don't need to add this all at the beginning, but if we plan well we could
add things later as needed:

- Switches (will require resistors, so let's use the internal pull-up resistors)
- Potentiometers 
- [Joystick](https://www.adafruit.com/product/504) (using internal pull-up resistors)

Do we want any outputs? Might be useful if we send messages back from robot
Let's see how many pins we have left, if we
assume we use both potentiometers and
6 switches:

How many pins have we used so far? 
- [Radio](https://lastminuteengineers.com/nrf24l01-arduino-wireless-communication/): 5 pins
- USB: 2 pins (0 and 1)
- Joystick: 5 pins
- Potentiometers: 2 analog input
- Switches: 6 pins

Total = 20, that uses all pins. We could wire LEDs to the same pins as
switches, that way we can select in software whether to use the pin as an
input or an output. Or we could only solder in what we want.

(Sometimes it's possible to overthink, and it's best to just start making)

Schematic

Connectors:

- Radio: 8 pin socket (2 rows of 4)

Now we think about how to lay out all these components:
- Switches
- LEDs
- Joystick
- Potentiometers
- Radio connector

Some prototyping shields have designated spaces for LEDs or switches. Would
this be useful for us? What pins are they connected to?

**Make sure you are putting the components on the right side!**

Take pictures along the way. They might be useful for documentation and to
remind yourself where you planned to put things.

Now that we know where things go let's start with the bare minimum, maybe
- Radio
- Joystick
- Designated LEDs and switches

### November 1

#### Administration
- Record 
- End of semester show might move to Wednesday

#### Discussion
- Chapter 5: Robots: Asleep, Awake, Alone, and in Love (Jana and Zhiyang to
leave)
- Discuss Spot


### November 3

#### Meditate

#### Administration
- Record 
- Reschedule those who doing capstone until after panel (who is that?)

#### Presentations
- Tori
- Katie

#### Work along with me
- Joystick, radio, potentiometers

### November 8

#### Administration
- Record 

#### Presentation
Amina: *Performance of Disabled Robotics* 

#### Discussion
On Stage: Robots as Performers (Amina and Yasmine)

#### Homework
- Performance proposals
- Circuit

### November 10

#### Meditate

#### Administration
- Record 
- Meet in the lobby of the Art Center on Monday, November 15, at 10:25

#### Work along with me
- Radio

Monday
----

![](media/shieldTop.jpg)
![](media/shieldSideA.jpg)
![](media/shieldSideB.jpg)
![](media/shieldBottom.jpg)
![](media/shieldNotes.jpg)

### Monday November 15

#### Administration
- Record 
- Sadly the visit to the robot lab is cancelled due to sickness so we'll meet
	online as usual

#### Presentation
- Coco
- Yasmin

#### Lab
- Solder the headers

Finished transmitter remote control on a prototyping shield:
![](media/topFinished.jpg)
![](media/bottomFinished.jpg)

### November 17

#### Meditate

#### Administration
- Record 
- The 'Other' Actor (Katie and Coco)?

#### Work along with me
- Test our RC radio shields
	- First individually with built in examples
	- Transmitter
		[code](https://github.com/michaelshiloh/resourcesForClasses/tree/master/src/arduinoSketches/nRF24L01/rf24XmitShield/rf24XmitShield.ino)
	- Receiver 
	[code](https://github.com/michaelshiloh/resourcesForClasses/tree/master/src/arduinoSketches/nRF24L01/rf24Rcvr/rf24Rcvr.ino)

#### Discussion: Our performance!

### November 22

#### Administration
- Record 
- Nov 28 make up class for Dec 1

### November 24

#### Meditate

#### Administration
- Record 
- We meet on Sunday November 28 on Wednesday schedule
- No class Monday or Wednesday

#### Presentation: Aalya, Salama (if ready)
#### Discussion: Digital Theatre (Katie and Coco) (if ready)

Further to the discussion of robot rights:

"It was not, of course, only slaves who have lacked many
of the rights that today we accept as basic and fundamental
bastions of a civilised society. As Robert Freitas Jr. remarked
in his 1985 essay The Legal Rights of Robots, in the past,
blacks, gypsies, children, women, foreigners, corporations,
prisoners, and Jews have all been regarded at some points in
history as being legal non-persons."

[The Ethical Treatment of Artificially Conscious
Robots](https://github.com/michaelshiloh/resourcesForClasses/blob/master/doc/theEthicalTreatmentOfArtificiallyConsciousRobots.pdf)  
By David Levy  
Int J Soc Robot (2009) 1: 209–216  
DOI 10.1007/s12369-009-0022-6

#### Discussion: Our performance!

Notes are
[here](https://docs.google.com/document/d/1UHZr9MYWIdmxLi_zSS8DHFCW8sF6HJgSkXM54YfF8e4/edit)

### November 28

##### Meditate
##### Record!
##### Presentation and Discussions
- Presentation by Salama
	- Quote on first slide
	- "More and more I think Robotics is really just the 
	Philosophy version of Engineering… " - Kyle
- Reading discussion delayed until next week

##### Final project
- What did we decide regarding queen?
- Break into groups, write script
	- Lots of robot action (movement, LEDs) to show off your robots

##### Todo
- Build robots: each his/her own
- Queen: Michael
- Test multiple robots in same room (different addresses): Michael
- Sound track: unassigned
- Create scenery: unassigned

### December 6

##### Record!
##### Announcement
Virtual Visit: Interactive Media and Beyond 
with Bruce Sterling and Jasmina Tešanović
When: Dec 6th, 6–7:30pm
[Zoom Registration](https://nyu.zoom.us/meeting/register/tJEqduCqrT8vHNQ-k6jf7UZntEoUEKzvr0O-)

Bruce Sterling and Jasmina Tešanović have been invited to read from their recent work and engage in a conversation about Interactive Media and beyond. Topics this discussion may touch upon include but are not limited to: futurism, speculative technology culture, Arduino, maker culture, and buzzwords such as NFTs, the IoT, cyberspace vs. metaverse, to name a few. This event will be moderated by professors Heather Dewey-Hagborg and Joerg Blumtritt.

Bruce Sterling is a writer, journalist, design philosopher and futurist. He has written many science fiction novels and short stories that have earned him several Hugo awards and other prizes. As a writer and editor of anthologies like MIT’s Twelve Tomorrows, Bruce plays a central role in shaping the genre of cyberpunk.

Jasmina Tešanović is a feminist, political activist, writer, journalist, musician, translator, and film director. She is known for her engagement in the international movement Women in Black, particularly during the Yugoslavian civil war and its aftermath, and the international feminist peace movement Code Pink. In 1978 she promoted the first feminist conference in Eastern Europe, “Drug-ca Žena” (“Commrad Women”, Belgrade). She co-created “Feministička devedeset četiri” (Feminist 94”) a pioneering feminist publishing house. With “The Scorpions: Genocide in Srebrenica” as well as the “Diary of a Political Idiot” on the 1999 war over the Kosovo, and her reports from the trials in The Hague, Jasmina has played an important role as chronist of the atrocities in the Balkans.

##### Presentation and Discussions
- Presentation by Salama
- Discussion of reading

### todays-lecture
### December 8

##### Record!
##### Announcement
show stuff

##### Power

