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

Shortcut to [Today's assignment](#todays-assignment)

This is subject to change

### This document: Weekly Schedule

This includes:
- Weekly topic(s)
- Production assignments
- Reading assignments
- Projects

This is all subject to change

### Week 1 (September 7 and 9)

Preparations, Basic Electronics, and Introduction to Arduino

#### Assignments Due September 14

Email Assignment:

- Join Discord. Email me if you are missing the invitation.
- Create your github account and repository. Email me a link to your github repository.
- Choose a topic, 
	related to Performing Robots, 
	possibly inspired by [this](references.md) list, on which
	you will give a 10 minute presentation later in the semester.

  Your topic can be an article, a robot, a performance, a book, an artist,
	an event, etc. 

	Your topic can not be a movie or book of fiction. (e.g. not Wall-E or
	Terminator)

  Email your topic to me, which I will
  put on our website. You must pick a topic that no one else has chosen.

Reading Assignment:

- Read [this](doc/Eckersall_TowardsADramaturgyOffRobotsAndObject-Figures.pdf) essay
- Sparkfun [breadboard
	tutorial](https://learn.sparkfun.com/tutorials/how-to-use-a-breadboard/all)
- [Microcontrollers, the basics](https://itp.nyu.edu/physcomp/lessons//microcontrollers-the-basics/)
- [Digital Input & Output](https://itp.nyu.edu/physcomp/lessons//digital-input-output/)
- Read about 
[analog output](https://itp.nyu.edu/physcomp/lessons/analog-output)
- Read about
[analog Input](https://itp.nyu.edu/physcomp/lessons/analog-input/)
- If you are new to functions or want to review, 
watch Dan 
Shiffman's [functions](https://www.youtube.com/watch?v=XCu7JSkgl04&list=PLRqwX-V7Uu6ajGB2OI3hl5DZsD1Fw1WzR) tutorials. There are four videos, each less than 10 minutes.
- [Register](https://urldefense.proofpoint.com/v2/url?u=https-3A__nyu.us9.list-2Dmanage.com_track_click-3Fu-3D03ec7d03b3e32907c3e74fcb1-26id-3D2650eda65d-26e-3D7173815e95&d=DwMFaQ&c=slrrB7dE8n7gBJbeO0g-IQ&r=m4YMhYfi7FR2pb6VWfg2pA&m=dBV5Vamg2OlIs4dGOznCruep3PWs1Ql2EIh4kmkZ7xw&s=s40RaY7f5rmzuFAJ-LNzdWWsumQpM-wEkcHZCOYSeTc&e=) for and attend Invisible Threads: Technology and its Discontents
Wednesday, September 9th, 7pm (GMT+4) | 11am EDT

Production Assignment:

- Prepare a space for working with electronics
	- Have some space to work. There are many small components in the kit that
	will be easily lost, so ideally be seated at a table or desk with clear
	space around you.
	- The kit will include a hot glue gun. You will need a safe place with an
		electric outlet to work. To protect your work surface from drops of hot
		glue, cover it with cardboard or paper. You will need to keep the hot glue
		gun out of the reach of children or animals.
	- You will be building a robot. In order to give each robot its unique
		personality, start collecting cardboard boxes for constructing the robot,
		and varied items that can be glued to your robot. Wooden items such as
		coffee stirrers or popsickle sticks, plastic items like bottle caps, and
		cardboard such as toilet paper tubes are excellent candidates. If you have
		younger siblings consider things like pieces of broken toys and game
		tokens. Look for interesting scraps in your recycling bin and when you
		walk outside.
- Install the Arduino IDE from
	[here](https://www.arduino.cc/en/Main/Software). If you are on Windows chose
	the Windows Installer.
- Using Tinkercad, build a circuit with at least two momentary switches 
	(often called buttons), and at least
  two LEDs. Write a program that does something interesting in a creative 
	way.  Each switch must not simply turn on a corresponding LED.
- Document your work:
	- Create a new folder in your github repository called “September14"
	- Describe your project in README.md and include:
		- A description of your concept and how it was achieved
		- A screenshot of your circuit
			- Your schematic, whether hand drawn or otherwise, must be clear.
			- **Remember what a schematic is and is not.**
			- **Make sure your schematic is big enough to read without enlarging**
		- Problems, if any, and solutions, if any
		- Anything else you can think of
	- Upload your program.
		- Excellent names for variables and functions
		- Well structured
		- Proper indentation
		- Excellent comments
		- Keep the .ino extension so that it is formatted properly.

### Week 2 (September 14 and 16)

Much More Arduino, QWIIC

#### Assignments Due September 21 

Reading Assignment:

-  Read [Eckersall](doc/Eckersall_TowardsADramaturgyOffRobotsAndObject-Figures.pdf) and be prepared to discuss
-  Read the table of contents of
[socialRobotics.pdf](doc/socialRobotics.pdf)
and chose one article for which you lead the discussion.
- Read one of the explanations of Blink without Delay 
  [here](https://github.com/michaelshiloh/resourcesForClasses#blink-without-delay-resources)
	and try to understand how it works
- Read this Excellent Adafruit Multitasking
[Tutorial](https://learn.adafruit.com/multi-tasking-the-arduino-part-1?view=all)
- Read about the [SparkFun QWIIC](https://www.sparkfun.com/qwiic) system

Production Assignment:

- If you have never used a hot glue gun, 
practice some of the construction techniques that I showed in class.
This assignment won't be graded, so be creative and experiment. 
Post pictures of the process and the results.


### Week 3 (September 21 and 23)

- Guest talk (Kid Koala)
- Adafruit OLED display

#### Assignments Due September 28

Reading Assignment:

- Read *Initial Formation of Trust: Designing an Interaction 
	with Geminoid-DK to Promote a Positive Attitude for Cooperation* 
	from [socialRobotics.pdf](doc/socialRobotics.pdf)
	and be prepared to discuss (pg. 95 in the document; 107 in the pdf)
- - Watch at least the first four of Dan shiffman's [Object Oriented
  Programming](https://www.youtube.com/watch?v=YcbcfkLzgvs&list=PLRqwX-V7Uu6bb7z2IJaTlzwzIg_5yvL4i)

Production Assignment:

- Write a program that uses the button and the OLED display
	- You will need to combine elements from the button example
		(Example1_PrintButtonStatus) and the OLED example (SSD1306_128x64_i2C).
	- In `setup()`, your program should display the word "Ready"
	- In `loop()`, your program should check to see if the button is pressed
		- If the button is pressed 
			- Count how many times the button is pressed
			- Change the text to say "Pressed"
		- When the button is released
			- Change the text to display how many times the button was pressed


### Week 4 (September 28 and 30)

MP3 Trigger, Motor Driver, Introduction to Multitasking

#### Assignments Due October 5

Reading Assignment:

- Read *Children Interpretation of emotional body language 
	displayed by a robot*
	(page 62)
	from [socialRobotics.pdf](doc/socialRobotics.pdf)
	and be prepared to discuss

Production Assignment:

- Using the Motor Driver and the MP3 Trigger, build a contraption that will
	drive around and make sound
	- Optional: Use the button to initiate the activity. Contraption will
	perform activity once and then stop, and repeat if button is pressed again

### Week 5 (October 5 and 7)

Asynchronous operations, OLED, expressiveness

##### todays-assignment
#### Assignments Due October 12

Reading Assignment:

- Read 
	*Examining the Frankenstein Syndrome: An Open-Ended Cross-Cultural Survey*
	(page 62)
	from [socialRobotics.pdf](doc/socialRobotics.pdf)
	and be prepared to discuss

Production Assignment:

- Add the OLED display to your motorized contraption, 
- Use it to give your contraption the ability to be expressive.
- Create a 1-2 minute performance that your contraption can perform.
- Use the button to initiate the performance, and have it stop
after performing once. 
	- Optional bonus: Pressing the button again restarts the performance
- Document your work properly with and a link to a video.
	- No schematic is required.

### Week 6 (October 12 and 14)

MP3 player

#### Assignments Due October 18

Reading Assignment:

TBA

Production Assignment:

Motorized contraption, OLED display, with sound

### Week 6.5 (Oct. 18, Sunday, Legislative day – classes meet on Wednesday schedule)

## Fall Break-ish 

### Week 7 (October 26 and 28)

Robotic Performance concepts

#### Assignments Due November 2

Reading Assignment:

TBA

Production Assignment:

First draft

### Week 8 (November 2 and 4)

Debugging

#### Assignments Due November 9

Reading Assignment:

TBA

Production Assignment:

TBA

First prototype of final project due

### Week 9 (November 9 and 11)

Second draft

#### Assignments Due November 16

Reading Assignment:

TBA

Production Assignment:

TBA

### Week 10 (November 16 and 18) 

Start working on final robot

#### Assignments Due November 23

Reading Assignment:

TBA

Production Assignment:

First iteration, final robot 

### Week 11 (November 23 & 25)

#### Assignments Due November 30

Production assignment: 

Second iteration, final robot 

### Week 12 (November 30 only)

Performance rehearsal

December 2: National Day Holiday (No classes)

### Week 13 (December 7 and 9)

Final Project Due

