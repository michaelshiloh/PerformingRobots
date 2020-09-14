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

[Today's lecture](#todays-lecture)

### Week 1

### September 7

Administration

- Record lesson

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


### todays-lecture

Administration

- Welcome to week 2!
- Record lesson
- Questions about the homework

Test Arduino IDE
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

Time permitting
- Adafruit Multitasking Tutorial

production homework
build something with hot glue
	- ungraded, since some students don't have kits yet
