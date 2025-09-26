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

### Assignments Due Thursday August 28 Week 1

Bring to next class Assignment:

- If you have a modern laptop with only USB-C ports, you will need a USB-C to
  USB-A adapter, something like this: 
![](media/USBC-USBA_adapter.jpg)

Outfit Assignment:

- Next week you will be doing tool training. For this you need to dress
  properly:
  - Closed toed shoes
  - No loose clothing (smocks can be provided)
  - No necklaces or bracelets or other dangling jewelery
  - Expect to get dusty (sawdust, metal shavings)

Email Assignment:

- Join Discord
- Create a Github account, if you do not have one. Instructions are
  [here](https://github.com/michaelshiloh/resourcesForClasses#github-resources)
- Create a repository called "performingrobots" in your Github account. 
- Send me email with:
    - A link to your github *repository* (not the account!!!!)
    - Discord screen name 

Reading Assignment:

- Review or learn the following:
    - What is an Arduino
    - How to use `setup()` and `loop()`
    - How to use the `digitalWrite()`, `digitalRead()`, `analogWrite()`, and
      `analogRead()` functions
    - How to use the internal pullup resistors
    - How to wire up a switch and an LED on a solderless breadboard
    - How to use the `if ... else` construct
    - How to use an L298 H-bridge to control the direction and speed of a
      motor

There are millions of resources on the web. Here is a short list or find your
own:
- Breadboard
    - Video: https://www.youtube.com/watch?v=6WReFkfrUIk
    - Text: https://www.build-electronic-circuits.com/breadboard/
- Switches
    - Video: https://www.youtube.com/watch?v=ChHNI8yt69g
    - Text:https://learn.sparkfun.com/tutorials/button-and-switch-basics/all#:~:text=A%20switch%20can%20only%20exist,piece%20of%20perfectly-conducting%20wire.
- LEDs
    - Video: https://www.youtube.com/watch?v=I0ZIrzoI61g
    - Text: https://learn.adafruit.com/all-about-leds/overview
- Analog/Digital Input/Output
    - Video:
        - https://www.youtube.com/watch?v=cmc-BPtkdAU
        - https://www.youtube.com/watch?v=JwpBn1mPGMc
        - https://www.youtube.com/watch?v=8bufqdXwCpY
    - Text: 
        - https://arduinofactory.com/arduino-language-analog-pins-analogwrite-and-analogread/
        - https://arduinofactory.com/arduino-language-digital-pins-digitalwrite-and-digitalread/
- If… else
    - Video: https://www.youtube.com/watch?v=YktSocf2vSc
    - Text: https://docs.arduino.cc/built-in-examples/control-structures/ifStatementConditional/
- While Loop
    - Video: https://www.youtube.com/watch?v=ECHFxmKUDFQ
    - Text: https://www.sparkfun.com/news/2399
- L298 H-bridge
    - https://deepbluembedded.com/arduino-l298n-dc-motor-driver-interfacing-tutorial/
    - https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/
    - https://howtomechatronics.com/tutorials/arduino/arduino-dc-motor-control-tutorial-l298n-pwm-h-bridge/

### Assignments Due Thursday September 11
1. Finish mounting the caster wheel and the two motors to your wooden
   platform. You can use the tools in the IM lab whenever it is staffed,
   either by Dustin or a lab assistant. 
	1. Be sure to clean up after yourselves.
	1. Obey safety protocols
	1. Wear closed toed shoes and safety glasses
	1. Dress properly: hair tied back, no loose jewelery or clothes, etc.
1. Since we will be doing a lot of fabrication in this class, I suggest that
   you always dress appropriately.
1. We need to start working on the play. Please bring to class **two**
   concepts for plays.

### Assignments Due Tuesday September 16

#### Play
Create an outline of the play consisting of at least five scenes. For each
   scene, list the characters involved and summarize the scene. Typically, all
   characters will be in the first and last scene: 
1. Beginning scene (sort of an introduction)
1. Intermediate scene A
1. Intermediate scene B
1. Intermediate scene C
1. Final scene (wraps up any loose ends, closes the play)

#### Arduino
1. Refresh your memory of how to use **arrays** in Arduino. Use any resource you
   like, such as
   [this](https://docs.arduino.cc/language-reference/en/variables/data-types/array/)
   or
   [this](https://docs.arduino.cc/built-in-examples/control-structures/Arrays/).
   If you find a different resource that you find particularly useful, please
   post it on our Discord channel.
1. Read [this](https://ece353.engr.wisc.edu/firmware-basics/interrupts/) very basic introduction to **interrupts**. 
1. Read [this](https://ryanboland.com/blog/reading-rc-receiver-values)
   description of using the **EnableInterrupt** library to read the signals
   from a Hobby RC radio receiver

#### Soldering
Read the first two of the following
guides on soldering, and watch the third video between 0:17 and 0:28 seconds.
Play the video over a few times and pay careful attention. 
- Note how the solder **sticks to both the pin and the round pad on the
  circuit board.**
- Note that **only just enough solder is used**, so as not to create
  an unwanted connection (a *short circuit*) between two pins.

Soldering Resources [here](https://github.com/michaelshiloh/resourcesForClasses/tree/master?tab=readme-ov-file#soldering)

### Assignments Due Thursday September 18
1. Create an outline of the play 
1. Before class, one person from each team should go to the Equipment Center
   (near the Project Space) and check out the RadioLink RC4GS kit with the RC transmitter,
   receiver, batteries, and battery charger. 
1. Dress appropriately for working in the IM fabrication area

### Assignments Due Tuesday September 23

- Finish attaching the Arduino, L298 H-bridge, and battery to your robot base
- Drill holes in based to allow the wires from the motors to come to the top
- Extend the motor wires by soldering. If your soldering looks excellent, and
  if you know how to use heat shrink tubing, you may insulate your solder joint
  with heat shrink tubing. If you are unsure, leave your wires exposed until I
  can inspect them (Monday or in class).
- Charge all six of your AA batteries for the RadioLink RC4GS transmitter

#### todays-assignment
### Assignments Due Thursday September 25
#### Soldering

Make some progress on the soldering work we discussed today. I have
added
more [detailed
notes](https://github.com/michaelshiloh/PerformingRobots/blob/master/lectureNotes.md#soldering-wires-between-l298-breakout-board-and-hobby-rc-and-motor-controller-shield) in the lecture notes. I will try to add pictures too.
Watch the videos first.

#### todays-assignment
### Assignments Due Tuesday September 30

#### Robot base
Finish your robot base. That includes:
- All wiring
- Pair your radio transmitter and receiver
- Combine the code for controlling the motors with the code for reading the
  radio signals. At the very least:
  - Robot can move forwards and backwards by remote control at a fixed speed
- Bonus:
    - Add the ability to steer your robot i.e. to make turns
    - Add the ability to vary the speed

#### Research Presentations
- Presentations will start on October 14 
- Presentations will happen on Tuesdays
- We will have three presentations per day
- Select a date for your presentation on the 
  [same](https://docs.google.com/spreadsheets/d/1H67fPcgNpJAw_h9IF7Uh4UINfpykP3S3smrm_njblvk/edit?usp=sharing) list

#### Research topics
In groups of two, choose two research topics on which you will give a
presentation: 1) a team or individual creator (artist, designer, engineer) who
creates robotic performers or performances and 2) a machine or device that is
a robotic performer. You can define the word "robot" quite broadly, but it
must have a physical presence and physically interact with the world outside
of a computer screen.
- Do not work with your robot partner
- Choose a different group of two for each presentation
- In-depth, serious research, analysis and critique are required. Your presentation must not
  simply be a collection of facts. Use the library and the writing center. I
  will provide more detailed guidelines.
- You may find some inspiration in these
  [references](https://github.com/michaelshiloh/PerformingRobots/blob/master/references.md)
  or in these
  [resources](https://github.com/michaelshiloh/resourcesForClasses). 
- Enter the names of your chose topics in
  [this](https://docs.google.com/spreadsheets/d/1H67fPcgNpJAw_h9IF7Uh4UINfpykP3S3smrm_njblvk/edit?usp=sharing)
  list. If a topic is already chosen, you must choose another. After your
  presentation, add a link.
- Presentation can be of any form. 

