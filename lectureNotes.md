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

Time Permitting:

Suppose we want to cycle through some behavior when a button is pushed. How
would we do this?
- Edge detection
- State Machine

### todays-lecture
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
- Tining the tip

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

##### Prepare H-bridge

- How to use a screwdriver
	- Especially if the size is wrong or the screws are poor quality
- Gently pry open 
- Prepare ground jumper
- Insert battery wires, carefully observing polarity
	- Red is +Vcc
	- Black is GND
- Attach motor wires (polarity doesn't matter)
- Attach jumpers for H-bridge
- Code
	- Need to set up Arduino first
- Enjoy

#### Digital Multi Meter

- Battery
- Measuring resistance
	- Resistor
	- Motor
	- LED
	- Yourself
- Measuring voltage:
	- Battery
	- Arduino 5V
	- Arduino output
