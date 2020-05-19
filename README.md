# SocialRobot

For Arduino with Shiftr.io

We invite you to join us in exploring the ways in which social robotics can support people in creating and discovering their social patterns and needs.

Our master branch contains all the code necessary for a basic set up, input and output. We have tried to make this process as modular as possible, so once you have your basic set up complete you can go wild! Customise your bot by using different sensors/actuators as input/output.
Fork the repository or contribute to the Social-Robotics project.
Our 'projects' branch, includes the various ways participants (including us!) have combined the different elements to best suit our social needs.
For full instructions, background on the project and our stories visit our platform ---> ......

Core team VJPW

License Social-Robotics is licensed under the MIT license. https://opensource.org/licenses/MIT

Code of Conduct (do we need this?) This project and everyone participating in it is governed by the '...' Code of Conduct. By participating, you are expected to uphold this code. Please report unacceptable behavior to '...'.

Contributing Pull requests welcome

# Step 1: Setup Arduino Schematics

Link to Forum Arduino Schematics

[And see Schematics explained here](SetupArduinoBoard.md)

# Step 2: Install code

**Go to the following link to install Arduino on your laptop:** 
https://www.arduino.cc/en/Main/Software

**Go to the follow Github link to grab your Arduino code:**
[Basic code](SetupArduinoBoard.md)

**Install the MKR WiFi 1010 Arduino board to get started:**

Hulpmiddelen —> Board —> Board Beheer —> Search for

Arduino SAMD Boards (32-bits ARM Cortex-M0+) by Arduino

.

**Install the following two libraries to get started:**

Go in Arduino to  Schets —> Bibliotheek gebruiken —> Bibliotheek beheren —> Search for:

WiFiNINA by Arduino

MQTT by Joel Gaehwiller

MQTT Client by Andreas Motzek - click install all

And press on Install

# Step 3: Change the code to your situation

**Assign which subscriber you are:**

Set on line 118 and line 122 which button you are.
```
client.publish("/button1", “1");

client.publish("/button1", "0");
```
Here you see your button 1.

.

**Setup WiFi and MQTT login code:**

On line 6 and 7 you see:
```
const char WIFI_SSID[] = “”;

const char WIFI_PASS[] = "";
```
Fill in between “" your WiFi ID and Password.

.

On line 10, 11 and 12 you see:
```
const char key[] = ""; 

const char secret[] = "";

const char device[] = "";
```
Fill in between “" your key and secret you got from https://shiftr.io/ and name yourself is device.

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

Link to Forum Code explained

[And see Code explained here](ExplainBasicCode.md)

# Explain shiftr.io

Link to Forum Shiftr.io explained

https://shiftr.io/get-started

