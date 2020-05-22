# SocialRobot

We invite you to join us in exploring the ways in which social robotics can support people in creating and discovering their social patterns and needs.

Our master branch contains all the code necessary for a basic set up, input and output. We have tried to make this process as modular as possible, so once you have your basic set up complete you can go wild! Customise your bot by using different sensors/actuators as input/output.
Fork the repository or contribute to the Social-Robotics project.
Our 'projects' branch, includes the various ways participants (including us!) have combined the different elements to best suit our social needs.
For full instructions, background on the project and our stories visit our platform ---> ......

Core team VJPW

License Social-Robotics is licensed under the MIT license. https://opensource.org/licenses/MIT

Code of Conduct (do we need this?) This project and everyone participating in it is governed by the '...' Code of Conduct. By participating, you are expected to uphold this code. Please report unacceptable behavior to '...'.

Contributing Pull requests welcome

Now we're gonna explain to you how you can set up the basic setup of the robot:

# Step 1: Setup Arduino Schematics

[And see Schematics explained here](SetupArduinoBoard.md)

# Step 2: Install code

**Go to the following link to install Arduino on your laptop:**

https://www.arduino.cc/en/Main/Software

.

**Go to the follow Github link to grab your Arduino code:**

Download the code with the green button in the top right corner and use the **folder Basic_LEDS.**

.

**Install the MKR WiFi 1010 Arduino board to get started:**

You need to install the specific board manager to be able to recognize the right Arduino Board.

Tools —> Board —> Boards Manager —> Search for

Arduino SAMD Boards (32-bits ARM Cortex-M0+) by Arduino

.

**Install the following two libraries to get started:**

You need to install the specific library to be able to recognize the code that make the connection with the WiFi and the Shiftr.io MQTT broker.

Go in Arduino to Sketch —> Include Library —> Manage Libraries —> Search for:

WiFiNINA by Arduino

MQTT by Joel Gaehwiller - you need to scroll more down to be able to find it

MQTT Client by Andreas Motzek - click install all 

And press on Install

# Step 3: Change the code to your situation

For this check in Preference: display line numbers.

**Assign which subscriber you are:**

Set on line 116 and line 120 which button you are, so /button1 or /button2 etc.
```
client.publish("/button1", “1");

client.publish("/button1", "0");
```
Here above in the code you're seeign that your assigned as button 1.

.

**Setup WiFi and MQTT login code:**

On line 6 and 7 you see:
```
const char WIFI_SSID[] = “”;

const char WIFI_PASS[] = “”;
```
Fill in between “” your WiFi ID and Password.

.

On line 10, 11 and 12 you see:
```
const char key[] = ""; 

const char secret[] = "";

const char device[] = "";
```
Fill in between “” your key and secret you got from https://shiftr.io/

At device[] between “” you can assign your name, so that on Shiftr.io you can recognize who you are.

.

**Assign the pins:**

On line 21 you see:
```
const int buttonPin = ;
```
Fill in between = and ; your buttonPin number coming from the breadboard.

.

On line 27 till 30 you see:
```
int ledPin1 = ;

int ledPin2 = ;

int ledPin3 = ;

int ledPin4 = ;
```
Fill in between = and ; your ledPin number coming from the breadboard. 

Do it from left to right, so you know later from who the led light is coming.

# Step 4 Run the code

Now you are ready the run the code.

You're able to start clicking the button to signaling over to eachother and switching lights on and off. 

Also you can see yourself on shiftr.io.

# Error solving

Circuit: 
- Can be that you need to turn the long and short leg of the led with eachother
- Do used the right resistor and is it in the right row
- Did assigned it to the right pin

Connecting the board:
- Be sure you installed the board manager for MKR WiFi 1010 Arduino
- Select the right port and board
- Still don't recognize, try to reset the Arduino by dubbel clicking on the reset button.

Run the code doesn't work:
- See if you installed all the libraries
- See if you not accidentally wrote something in the code
- New assigned variables are assigned at the top

Still not working:
- Did you assigned the right pin number for the leds and button?
- Is your WiFi code correct?
- Is your MQTT code correct?
- Both subscriber assigned in Basic_LEDS and in connect file
- Check the serial monitor in the right up corner if your getting signals through. You can test with this by writing Serial.print(); in between code.

# Explain code

[And see Code explained here](ExplainBasicCode.md)

# Explain shiftr.io

https://shiftr.io/get-started

[And see Shiftr.io explained here](Shiftr.ioExplained.md)
