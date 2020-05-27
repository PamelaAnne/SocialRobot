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
