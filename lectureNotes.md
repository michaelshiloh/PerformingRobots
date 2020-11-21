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
Meeting times:    
1:15 PM - 3:55 PM M  
1:15 PM - 2:30 PM W  
Session: Fall 2020    
[Link](https://nyu.zoom.us/j/99801224178) to class Zoom meetings

This is subject to change

This document: Lecture Notes

### Week 1

### September 7

Administration

- Record 

Introduction

- What is a robot?
- What is performance?
- Watch some videos
	- [Welcome to Duloc](https://www.youtube.com/watch?v=X81AoBcVnaA)
	- [Survival Research Labs](https://youtu.be/aZwkvM4BzN4?t=302)
	- [Bot and Dolly](https://youtu.be/lX6JcybgDFo?t=132)
	- [Oriza Hirata](https://youtu.be/CWnnqObk1qM)
	- [Robotic Church](https://vimeo.com/114296519#t=120s)

- Who am I?
- [weekly schedule](weeklySchedule.md)
- [Syllabus](syllabus.md)
- Summary:
  -  Be present and participate in class
  -  No electronic distractions
  -  Be proactive: Communicate with me regarding difficulties, problems, illness, etc.
  -  Allow lots of time for homework as physical construction
  and debugging circuits and programs can be very time consuming.
- Who are you?

Getting Ready

- Collecting stuff
- Cardboard
- Space
- Hot glue gun
- Rubbing Alcohol

Do along with me

- Discord
- Github
- Tinkercad

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

- Edit your README.md file
	- What is README.md?
	- What is .md?
- Simple Markdown 
	- **Bold**
	- Paragraphs must be separated by a blank line
	- Inserting images: ![](media/eye-calipers.jpg)
	- Always remember to commit your changes!
	- More [here](https://github.com/michaelshiloh/resourcesForClasses#github-resources).

**Tinkercad**

- Go to [Tinkercad](https://www.tinkercad.com) website
- Make an account with your NYU email address
- Create a project
- Select "circuit"

- Simple circuit
- Arduino
- LED + resistor
- Switch + resistor
- Conditionals
- Loops

### September 9

Administration

- Record lesson
- Discuss homework

Do along with me

- [Tinkercad](https://www.tinkercad.com) 
- Circuit
- Code
- ````if()```` statement (conditionals)
- ````for()```` loop
- Comparisons
	- Arduino reference page
	- Complex comparisons
- Communication
	- ````Serial()````
- Variables
- Functions
	- let's move the blinking into a separate function
	- Why use functions?
-	Making your program easier to read
	- For yourself and for others (e.g. your professor)
	- Good names for variables and functions
	- Functions
	- Indentation
	- Comments

Here is the example I did in class. I had made an error in both the code and
the circuit. See if you can spot the differences. First is what you saw
in class, with errors:

![circuitWithError](inClassExamples/september9/sept9CircuitWithError.png)
[Code](inClassExamples/september9/sept9CodeWithError.ino) with error

Now with corrections. Note where I used ````Serial.println()```` 
to help me find the problem:

![circuitWithError](inClassExamples/september9/sept9CircuitCorrected.png)
[Code](inClassExamples/september9/sept9CodeCorrected.ino) after corrections


### September 14

Administration

- Welcome to week 2!
- Record lesson
- Questions about the homework

Test Arduino 
- Install [CH340
	driver](https://learn.sparkfun.com/tutorials/how-to-install-ch340-drivers)
- IDE
- blink

What else can we do?
- Serial
- IO foursome

Review
- Varibles
	- int, float
	- Difference between 
		- Declaration, which creates, or allocates, the variable
		- Assignment, which gives it a value
- Varible scope
	- Local
		- Allocation and freeing
	- Global
		- Allocated and never freed
- Functions

Reminder:
- Good variable and function names
- Indentation (demonstrate CTRL-T)

In-class exercise:
- Write a function that blinks an LED 5 times
	- Call it from setup
	- Call it from loop
	- How would you make it happen only once from loop?
		- State variable

Functions with arguments
- One argument
- Multiple arguments
- Return value!

Here are the examples we developed in class. First 
a function that takes two arguments and returns nothing:

````
void setup() {
  Serial.begin(9600);
}

void loop() {
  sayHello(9.7, 107); // intentionally passed the wrong parameter to show what happens
}

// A function that takes two arguments and returns nothing
void sayHello(int someInt, float someFloat) {
  Serial.print(someInt);
  Serial.print("  ");
  Serial.print(someFloat);
  Serial.println(" hello");
}
````

And now a function that takes one argument and returns something:

````
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

boolean firstTime = true; // state variable remembers whether it's the first time or not

void loop() {
  if (firstTime == true) {
    float theAnswer = blinkTimes(5);
    firstTime = false;
    Serial.println(theAnswer);
  }
}

// A function that takes one argument and returns a float
float blinkTimes(int count) {
  for (int i = count; i > 0; i -= 1) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
  return (count / 3.0);
}
````

### September 16

Administration
- Record lesson
- Have any kits arrived?

Working with Hot Glue 
- Cleaning
- Safety
	- Don't touch tip
	- If you get glue on you, wipe it off
	- Cold water (not the glue gun!)
- Construction techniques

More Arduino!

Libraries
- What is a library?

QWIIC
- What is it?
	- What is serial?
	- I2C
	- one-to-one vs. a bus
- Introducing the SparkFun [QWIIC
button](https://learn.sparkfun.com/tutorials/sparkfun-qwiic-button-hookup-guide/all)
button
- Install library: SparkFun Qwiic Button
- Run example: Example 1 - Prints the button status.

Time Permitting
- What's the problem with this example?
	- Hint: What if you were doing other things?
	- Blink Without Delay
	- Adafruit Multitasking Tutorial

### September 21

Administration

- Checkin
- Record lesson
- Have any kits arrived?
- Dates for presentations
	- Sept 30 Benjamin
	- October 7 Aleksandra
	- October 14 Muhammad
	- October 28 Sadeq 
	- November 4 Zheki
	- November 11 Baraa
	- November 18 Liyan
- Dates for student lead discussions
	- Sept 30 Liyan
	- October 7 Baraa
	- October 14 Aleksandra 
	- October 28 Zheki
	- November 4 Muhammad
	- November 11 Sadeq
	- November 18 Benjamin
- Guest speaker today

Homework review

- Quick review of homeworks

Do along with me

- OLED display
	- Install
		- Adafruit_SSD1306 
		- Adafruit_GFX
		- Adafruit BusIO
	- Run this example
		- SSD1306_128x64_i2c example 
	- More information in
		[this](https://learn.adafruit.com/monochrome-oled-breakouts?view=all#arduino-library-and-examples) tutorial

Guest speaker: Kid Koala 
Eric San, a.k.a Kid Koala, is a world-renowned scratch DJ,
music producer, and award winning graphic novelist. He has released 6 solo
albums, 4 on Ninja Tune:_ Carpal Tunnel Syndrome_ (2000), Some of My Best
Friends Are DJs (2003), Your Mom’s Favorite DJ (2006) and_ 12 bit Blues_
(2012) and 2 on Arts & Crafts. He has published 2 graphic novels: Nufonia Must
Fall (2003) and Space Cadet (2011). He has been involved in collaborations
such as Gorillaz, Deltron 3030, and The Slew. Kid Koala has toured with
Radiohead, the Beastie Boys, Money Mark, A Tribe Called Quest, DJ Shadow, and
The Preservation.

An internationally recognized DJ, Kid Koala has worked on projects that appeal
to a wide variety of audiences. 

About 3 1/2 years ago Kid Koala gave a performance at NYUAD using robots,
and this fall Kid Koala created a family-friendly show in Robot
House Party. The three-part event will lead kids to build their own robot
suits and dance in them.


### September 23

#### Administration

- Record 
- Where should I put the presentation and discussion assignments?
	- move to studentGithubRepositories
- SD card adapters

#### Discussion

- Eckersall

#### State

- [State Change Detection](https://www.arduino.cc/en/Tutorial/StateChangeDetection)
- [Blink without Delay](https://github.com/michaelshiloh/resourcesForClasses#blink-without-delay-resources)

### September 28

#### Administration

- Record 
- Presentation and discussion assignments are all in
	[studentPresentations.md](studentPresentations.md)
- Who is leading the discussion next week? Please tell us what to read

#### Lecture

- [Multitasking](https://learn.adafruit.com/multi-tasking-the-arduino-part-1?view=all)

#### Do along with me

MP3 Trigger

- Sparkfun
	[documentation](https://learn.sparkfun.com/tutorials/qwiic-mp3-trigger-hookup-guide/all)
- Insert uSD card gently
	- **Caution**: Do not pull on the uSD card! It must be pressed to be released!
- Library: SparkFun MP3 Trigger
- Use USB-C cable to connect drigger
	- It should show up as a thumb drive
	- Copy an MP3 file to the card. You can use [this](media/T001.mp3) or
		[this](media/T002.mp3)
- Example: Example1-PlaySong
- What else can the library do?
	- Look at other examples
	- [Functions](https://github.com/sparkfun/SparkFun_Qwiic_MP3_Trigger_Arduino_Library/blob/master/src/SparkFun_Qwiic_MP3_Trigger_Arduino_Library.h)
- Start thinking about what kind of sounds your robot will make. Will it
	speak? What kind of a voice will it use? Will it make non-speech sounds?
	Start collecting sounds that might be useful. You can record your own or
	find them on the internet (be sure to document where you got them) e.g.
	[here](https://archive.org/details/HB01SFX)

Motor Driver

- Sparkfun
	[documentation](https://learn.sparkfun.com/tutorials/hookup-guide-for-the-qwiic-motor-driver)
- Connect motors (polarity doesn't matter)
- Connect battery connector 
	- **Caution** polarity is critical!!
	- **Caution** do not plug in the battery until you have checked 3 times
	that the polarity is right!!
	- **Caution** Do not touch the battery to the connector backwards!!
- Library: Serial Controlled Motor Driver
- Example: Copy example from
	[here](https://learn.sparkfun.com/tutorials/hookup-guide-for-the-qwiic-motor-driver#experiment-1-testing-the-motors)
	(scroll down a little bit)

Here is the motor dance code:

````
void loop()
{
  // do a little dance and then stop
  //    stop both motors for 5 seconds
  myMotorDriver.setDrive( LEFT_MOTOR, 0, 0); //Stop motor
  myMotorDriver.setDrive( RIGHT_MOTOR, 0, 0); //Stop motor
  delay (5000);

  // go forward for 10 seconds
  myMotorDriver.setDrive( LEFT_MOTOR, 0, 200);
  myMotorDriver.setDrive( RIGHT_MOTOR, 1, 180);
  delay(10000);

  // turn right just a little
  myMotorDriver.setDrive( LEFT_MOTOR, 0, 50);
  myMotorDriver.setDrive( RIGHT_MOTOR, 0, 25);
  delay(500);


  // if you don't want it to stop, remove this:
  while (1)
    ;

}
````

Construction Techniques with Motors and Wheels

### September 30

#### Discussions and presentations

1:15 Tegan: “Composition & Dramaturgy for Performing Robots“  
1:45 Liyan  

#### October 5

#### Administration

- Cameras on in class unless you have discussed with me and received email
	permission to leave it off
- Record 
- Bad USB cable!
- Jack introduction

#### Homework review

- Construction techniques
- Blocking vs. non-blocking functions
- How do you know when a non-blocking function is done?

#### Drive without delay

````
const unsigned long motorOnPeriod = 4000;
const unsigned long motorOffPerid = 1000;
boolean motorIsRunning = true;
unsigned long motorOnAt = 0;
unsigned long motorOffAt = 0;

void loop()
{
  unsigned long currentMillis = millis();

  // Check to see if it's time to turn the motor on
  if ((motorIsRunning == false) && (currentMillis - motorOffAt > motorOffPerid)) {
    //time to turn motor on
    mp3.playTrack(2); //play this song
    Serial.println("in if");
    myMotorDriver.setDrive( LEFT_MOTOR, 0, 70);
    myMotorDriver.setDrive( RIGHT_MOTOR, 1, 70);
    motorOnAt = currentMillis; //update the timer
    motorIsRunning = true;
  }
  // otherwise, check to see if it's time to turn the motor off
  else if ((motorIsRunning == true) && (currentMillis - motorOnAt > motorOnPeriod)) {
    //time to turn motor off
    stopping();
    motorOffAt = currentMillis; //update the timer
    motorIsRunning = false;
  }

  // checking switch
  // starting at stopping mp3 playback
  // display things on OLED
}
````

````
void loop()
{
  if (mp3.isPlaying() == true) {
    Serial.println("file is still playing");
  } else {
    Serial.println("file has finished playing");
  }
}
````

#### Expressive OLED!

[This](https://randomnerdtutorials.com/guide-for-oled-display-with-arduino/)
tutorial might be helpful


#### October 7

#### Presentations

- Benjamin: Sophia, a robot who was granted Saudi Arabian citizenship
- Aleksandra: Chico Macmurtrie 

#### Discussion

- *Children Interpretation of emotional body language displayed by a robot* 
	on page 62 (Baraa)

#### Expressiveness

[Heider and Simmel animation (1944)](https://www.youtube.com/watch?v=VTNmLt7QX8E)

#### Time permitting

How to trigger performance once and only once on button press, 
and then stop when done and wait for press again before starting again


*Important Concepts*
- Being able to reset to a beginning state without resetting the
	board (either by pressing the button or uploading the program)


#### October 12

#### Show projects

#### Discussion with Tegan

#### Catchup presentation(s)


#### October 14

#### Announcements

- Legislative day Sunday October 18 (Wednesday schedule)

#### Presentations

- Muhammad: Asimov's Runaround and the three laws on robotics 

#### Discussion

- *Examining the Frankenstein Syndrome: An Open-Ended Cross-Cultural Survey*
	(Aleksandra)

#### Homework

Shakespeare

Do you prefer minimal by 18, or better by 26?


#### October 18

#### Guest discussion: Judi for costumes and other special accessories


#### October 26

#### State Machines

- Code we developed in class is
	[here](src/QWIICstateMachineRobot/QWIICstateMachineRobot.ino)

#### October 28

#### Announcements

- Record
- Muhammad: Send me email as to what we should 
read for your November 4 discussion
- Jon Bonner will be with us Wednesday next week to discuss lighting
- Lynn Hershman Leeson will give a Community Talk on Sunday, November 1st, 7pm:

Join us for a community talk by artist and filmmaker 
[Lynn Hershman Leeson](https://www.lynnhershman.com/)
about her pioneering contributions to the fields of photography, video, film,
performance, artificial intelligence, bio art, installation and interactive as
well as net-based media art over the last fifty years. Lynn Hershman Leeson's
innovative work investigates issues that are now recognized as key to the
workings of society: the relationship between humans and technology, identity,
surveillance, and the use of media as a tool of empowerment against censorship
and political repression.

Registration to attend this event is required and can be filled out 
[here](https://forms.gle/GNAtFv6NvZpCtxus8).

#### Monday November 2

#### Administration

- Record
- Jon Bonner will be with us Wednesday next week to discuss lighting

#### Catch up project presentation
- Benjamin

#### Debugging
- One that worked: MP3 Trigger example 3: play a file (it's not a bug)
- One that didn't work (yet): My allQwiicStuff works but motionAndAnimationNoDelay does not

#### Lecture

[Link](https://diyusthad.com/image2cpp) to bitmap generator that Muhammad found


##### Code developed in class:

````
int state = 0;
int repetitions = 7;
unsigned long motionStartedAt = 0;
int innerSpeed = 50;
int outerSpeed = 180;
int duration = 500;

void loop()
{
  unsigned long currentMillis = millis();

  // for debugging
  Serial.print("state = ");
  Serial.print(state);
  Serial.print("\t time = ");
  Serial.print(millis());
  Serial.print("\t repetitions = ");
  Serial.print(repetitions);
  Serial.println();

  if (!repetitions) {
    stopMotors();
    return;
  }

  switch (state) {

    case 0: // initiate wiggle to the right
      leftForward(outerSpeed);
      rightForward(innerSpeed);
      motionStartedAt = millis();
      state = 1;
      break;

    case 1: //continue wiggling until time expires
      if ((currentMillis - motionStartedAt) > duration) {
        state = 2;
      }
      break;

    case 2: // initiate wiggle to the left
      leftForward(innerSpeed);
      rightForward(outerSpeed);
      motionStartedAt = millis();
      state = 3;
      break;

		// something is wrong here; there is no way to get to state 4
    case 3: //continue wiggling until time expires
      if ((currentMillis - motionStartedAt) > duration) {
        repetitions--;
        state = 0;
      }
      break;

    case 4:
      break;

    default:
      stopMotors();
      break;



  }
}

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
````

#### Discussion about final

- Make non-blocking classes to
	- Display animations on display
	- Movement (wheels)
- Discussion:
	- What shall we do for final performance?
		- Constrained or entirely unrestricted?
			- unrestricted with optional constraints for those who prefer
		- Technical difficulties:
			- Sound
				- subtitles
				- bluetooths speakers
				- computer sychronization
				- sound overlay
				- ok to remove mp3 trigger from robot if not being used
			- Accurate movements
				- rubber bands
				- experiment with accurate positioning
			- Difficulty seeing display
				- only when stopped
				- big images

what did you learn about building it this time that you would do
differently next time ?


#### Monday November 9

#### Administration

- Record

#### My homework
- usingButtonWithoutInit or Example1_PrintButtonStatus
- OLEDUsesLotsOfMemory

#### Arduino memory
- What is memory?
	- It's all 1s and 0s
		- So it's binary
		- But what is it really?
- How is memory organized
	- Each individual 0 or 1 is a single Binary DIgit, called a *bit* 
	- Bits are organized in groups of 8 called a *byte*
	- Memory is organzied as an array of bytes, each with a unique address
	- 1024 bytes are called a kilobyte
- Arduino memory
	- Different types of memory
		- Flash (32K bytes) - retained without power, can't be modified by program
		- SRAM (2K bytes) - lost without power loss, can be modified by program
		- EEPROM (1K bytes) - retained without power, can be modified by program
	- Why so many? And how are they used?
		- Flash: Where your uploaded program goes
		- SRAM: Where variables go
		- EEPROM: Rarely used (it's quite cumbersome)
	- How do I know how much is being used?
		- Output of compilation of OLEDUsesLotsOfMemory:  
		````Sketch uses 13806 bytes (42%) of program storage space. 
		Maximum is 32256 bytes.
		Global variables use 999 bytes (48%) of dynamic memory, 
		leaving 1049 bytes for local variables. Maximum is 2048 bytes.
		````
	- That looks like plenty, what was the problem with OLEDUsesLotsOfMemory?
		- From Adafruit_SSD1306.cpp:

		````
		bool Adafruit_SSD1306::begin(uint8_t vcs, uint8_t addr, bool reset, bool periphBegin) {
		if ((!buffer) && !(buffer = (uint8_t *)malloc(WIDTH * ((HEIGHT + 7) / 8))))
		return false;
		````

		- Now since WIDTH = 128, HEIGHT = 64, `malloc()` asks for 1136 bytes!
		- But we only had 1039 bytes available,
			so the ````malloc()```` fails 
			which causes ````begin()```` to fail 
			which is why we get the message ````SSD1306 allocation failed````
	- So what can we do?
		- Remember that we have much more program memory (Flash) than
		variable memory (SRAM). IN fact, we only used
		13806 out of 32256 bytes. Now since strings aren't going to change, they
		we can put them in program memory. The easiest way to do that is with the
		`F()` macro which uses the PROGMEM variable modifier
			- `Serial.println("this message consumes valuable SRAM");`
			- `Serial.println(F("this message is in Flash memory"));`
			- [Reference](https://www.arduino.cc/reference/en/language/variables/utilities/progmem/)
			for the `PROGMEM` variable modifier which is used by the `F()` macro 
- Excellent
	[reference](https://cdn-learn.adafruit.com/downloads/pdf/memories-of-an-arduino.pdf) about Arduino memory in general and in much more detail

#### New material
- [wiggleStateMachineClass](src/wiggleStateMachineClass/wiggleStateMachineClass.ino) the class implements the state machine internally
- [OLEDAnimationBruteForce](src/OLEDAnimationBruteForce/OLEDAnimationBruteForce.ino) large OLED animation, brute force method
- [Large OLED animation, using a
	class](src/OLEDAnimationClass/OLEDAnimationClass.ino)

#### Performance Constraint
The storyline of your final performance has to come from a song 
or a poem and has to incorporate some (or all) of the lyrics at some point, 
but spoken, not sung. Your song or poem could be from any culture and any
source: modern, classical, popular, epic, etc. 
Among your final documentation you will 
explain the original source and how you adapted it to your performance.

#### Homework
- Who is leading our conversation next week?
- Don't forget reading for Wednesday
- Production assignment


#### Wednesday November 11

#### Administration

- Record
- was memory lecture useful?

#### Monday November 18

- Arrays for animation frames
- Animation and wiggle at the same time, no delays, using classes


#### Wednesday November 18

#### Announcements

[Nov 18 & Nov 25] RSVP for IM Workshop Series: Making a Website from Scratch for Absolute Beginners (Part III & IV) - Fall 2020

Part III & Part IV of this workshop series are finally here! Please RSVP to confirm your attendance.

Please find the description of the two upcoming workshops below:

Part III: Wed, Nov 18, 5:30–7:30pm GST - Jekyll: Creating an Online Blog or Portfolio

In this workshop, you will learn how to create a fully-customizable blog or portfolio website with Jekyll. Thanks to GitHub’s native support of Jekyll, you will be able to host your site for free and manage the content of your site without the hassle of maintaining your own database.

Part IV: Wed, Nov 25, 5:30–7:30pm GST - p5.js: Creating Visuals, Animations, Games

This workshop gets you started with p5.js, a JavaScript library for creative coding. P5.js lets you do anything from creating simple visuals and animations for your website to designing complex interactions or even standalone games.

Note that, while not required, it is extremely helpful if you have some knowledge of HTML, CSS, and JavaScript before attending the above workshops. I have covered these topics in the Part I & Part II of this workshop series. You can find the recordings below:

IM Workshop Series, Part I: HTML & CSS - Designing Layouts, Content & Styles

IM Workshop Series, Part II: JavaScript - Adding Interactive Features


#### Discussions and Presentations

- Liyan: The work and ideas of Guy Hoffman 
- Benjamin A Midsummer Night's Dream (with flying robots)

##### todays-lecture
#### Monday November 23

#### Announcements

- Part IV: Wed, Nov 25, 5:30–7:30pm GST - p5.js: Creating Visuals, Animations, Games
