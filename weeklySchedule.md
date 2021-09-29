Shortcut to [today's assignment](#todays-assignment)

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

### This document: Weekly Schedule

This includes:
- Weekly topic(s)
- Production assignments
- Reading assignments
- Projects

This is all subject to change

### Week 1 (Aug 30 and Sept 1)

Preparations, Basic Electronics, and Introduction to (or Review of) Arduino

#### Assignments Due September 1

Email Assignment:

- Join Discord. Email me if you are missing the invitation.
- Create your github account and repository. Email me a link to your github repository.
- Choose a topic, 
	related to Performing Robots, 
	possibly (but not necessarily) from [this](references.md) list, on which
	you will give a 10 minute presentation later in the semester.
  - Your topic can be an article, a robot, a performance, a book, an artist,
	an event, etc. 
	- Your topic can not be a movie or book of fiction. (e.g. not Wall-E or
	Terminator)
  - Email your topic to me, which I will
  put on our website. You must pick a topic that no one else has chosen.
- Install the Arduino IDE from
	[here](https://www.arduino.cc/en/Main/Software). If you are on Windows chose
	the Windows Installer.
- There is a lot to read for next week, so you might want to start now

#### Assignments Due September 6

Production Assignment:
- Pick up your kit from the bookstore, and the book as well if it's there. (I
	can't remember if we're getting paper or electronic books)
- Prepare a space for working with electronics
	- Have some space to work. There are many small components in the kit that
	will be easily lost, so ideally be seated at a table or desk with clear
	space around you.
	- The kit will include a hot glue gun and a soldering iron. 
		You will need a safe place with an
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
- Start working on your presentation. We will start presentations on September
	13.

Writing Assignment:

- Read [this](doc/autonomousRobotsAsPerformingAgents.pdf) paper
	- In your Github repository, create a folder named 'september6'
	- In that folder, create a file named 'README.md'
	- In that file, write a response to the paper (about half a page, more if
		you wish)
 
Reading Assignment:

Read, review, or skim as you feel is necessary:
- Sparkfun [breadboard tutorial](https://learn.sparkfun.com/tutorials/how-to-use-a-breadboard/all)
- [Microcontrollers, the basics](https://itp.nyu.edu/physcomp/lessons//microcontrollers-the-basics/)
- [Digital Input & Output](https://itp.nyu.edu/physcomp/lessons//digital-input-output/)
- Read about 
[analog output](https://itp.nyu.edu/physcomp/lessons/analog-output)
- Read about
[analog Input](https://itp.nyu.edu/physcomp/lessons/analog-input/)
- If you are new to functions or want to review, 
watch Dan 
Shiffman's [functions](https://www.youtube.com/watch?v=XCu7JSkgl04&list=PLRqwX-V7Uu6ajGB2OI3hl5DZsD1Fw1WzR) tutorials. There are four videos, each less than 10 minutes.

#### Assignments Due September 13

Production Assignment:

- Prepare a second motor as we did in class. 
	- You might want to watch the
	recording of class to remind youself how to do it.
	- Make sure you pay attention to all the precautions so as not
	to damage the motor or soldering iron, and not to hurt yourselves
	- Test the motor by connecting it directly to a battery
- Connect the second motor to the other side of the H-bridge
- Remove the red wire that went from the 5V pin on Arduino 
	to the 5v on the H-bridge. It is not needed.
- Using the breadboard, connect a switch (pushbutton) to your Arduino
- Write a program that will make both motors turn when you press the switch

Presentations are due, although we will not do them all today

Guidelines for presentations

- Background: 
	The purpose of these presentations is to let us grapple with questions
	about robotic performances, such as:
	- What is a robot? 
	- What is a robot performer?
	- What is a performance?
	- Should robots be in performances? Why or why not?
	- Should robots replace human performers?
	- Should humans replace robot performers?
	- What does a robot performer do better than a human performer? Worse?
- Presentation should be 10-15 minutes long
- Presentation should be demonstrate critical thinking. 
	Don't just report the facts. 
	- What is the context for this presentation?
	- What questions did it raise?
	- How do you feel about it? Do you agree? Did it change your mind? Did it
		make you think about things differently?
- Presentation should end with some questions that will encourage us to think
	about how this presentation affects or changes our
	opinions about robotic performances

#### Assignments Due September 20

Production Assignment:

Build something that you choose to define as a robot
- You may define the word "robot" in any way that you wish
- Your robot must be able to move. You may use any of the motors at your
	disposal. This is only a weekend project so don't be too ambitious.
- Program some sort of sequence into the robot's movements. 
	- The sequence must
		be part of a story (existing or one you made up)
	- The sequence must be at least 10 seconds long
- Upload a video of the robot performing its sequence (Vimeo, Youtube, etc.) 
-Document your project in your Github repository
	- Make a new folder with the name "September20"
	- Upload some process pictures as well as pictures of the final result
	- Create a README.md file with the following information
		- Your definition of the word "robot"
		- Describe your process and include the process pictures
		- Describe the story and how the movement sequence tells it
		- A link to the video
		- Describe any difficulties you had and how you overcame them or worked
			around them
		- Describe anything interesting you learned or discovered
		- Anything else you wish to add

#### Assignments Due September 27

- If you don't already have a spare Arduino and breadboard, 
	reserve one in the IM checkout system .
	- Schedule the pickup for a time of your choosing, but before Monday
- Read
	[this](https://learn.sparkfun.com/tutorials/how-to-use-a-multimeter/all) or
	any other tutorial on using a multimeter
- If you need a review of the servo motor, read 
	[this](https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep)
	or any other servo motor tutorial

### todays-assignment

#### Assignments Due September 29
- If you didn't finish it in class, finish soldering the stranded 
	wires to the header socket and on the other end three short pieces of solid
	core wire for breadboard use. Test that your wire assembly works with 
	the `strandtest` example.
- Test that your second Arduino works by uploading the `blink` program 
	from the built-in examples
- Build a circuit with 2 pushbuttons and test that they both work with the
	`digitalReadSerial` built in example
- Using your other Arduino and breadboard, build a circuit with 
		two servo motors and two LEDs. Test both motors and both LEDs with any
		built-in example.
- Solder the USB connector to your second Powerboost and connect it with the
	other switch to the other battery. Test that it works properly.
- Make sure that the switches for both batteries are turned off (Powerboost
	LED should be off).

#### Assignments Due next Monday
-	Get from the lab 10 feet (3 meters) 
	of red and black wires stranded wire during
	open lab hours. The lab assistants have this ready for you to pick up.

#### Midterm project due October 13
Built a robot that can be remote controlled

- Your robot can have any shape: anthropomorphic, animal-like, 
	or completely imaginary. Be experimental!
- Your robot must be expressive in some way that an audience will respond to 
	- Might be expressions we're familiar with (happy, sad, fearful, aggressive, shy) or invent your own as long as audience will respond in some way
- You can use any or all the actuators that you have:
	- 6 DC gearmotors
	- 3 servo motors (we will review these in class)
	- NeoPixel matrix
	- Individual LEDs
- The motors can be used for locomotion or for expression; it's up to you
- In addition to the buttons, your remote control (transmitter) can use a
	potentiometer. We will review this in class.
- You should have at least one sequence which is triggered by a button. In
	other words, the button causes the sequence to start, but once started, the
	sequence runs automatically without further input from you until it is
	finished. We will review this in class. The sequence can include the
	NeoPixel matrix.
