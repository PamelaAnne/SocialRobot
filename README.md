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

Tools —> Board —> Boards Manager —> Search for

Arduino SAMD Boards (32-bits ARM Cortex-M0+) by Arduino

.

**Install the following two libraries to get started:**

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
Fill in between “” your key and secret you got from https://shiftr.io/ and name yourself is device.

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

# Explain code

[And see Code explained here](ExplainBasicCode.md)

# Explain shiftr.io

https://shiftr.io/get-started

[And see Shiftr.io explained here](Shiftr.ioExplained.md)
