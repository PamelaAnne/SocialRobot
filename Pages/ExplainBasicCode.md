# Explain basic code

Line 2-3: Libraries you download to be able to connect to WiFi and MQTT broker.

Line 6-12: Setup WiFi and MQTT broker of shiftr.io with Username and Password

Line 15-18: Setup the client of WiFi and MQTT

Line 21-24: Setup buttonPin and status

Line 27-30: Setup ledPins

Line 33: connect with function connect that you can see in the tab (explain later)

Line 37: connect to serial monitor to use to check if values coming through

Line 39-43: setup ledPins as outputs and buttonPin as input.

Line 45: setup function connect

Line 51-94: here you get the subscribed values from other people through.

Line 53-62: if the first person called button1 (topic) published the signal(payload) of “1”, then ledPin1 HIGH (on). If signal(payload) of “0”, then ledPin1 LOW (off).

Line 63-74: if the first person called button2 (topic) published the signal(payload) of “1”, then ledPin2 HIGH (on). If signal(payload) of “0”, then ledPin2 LOW (off).

Line 75-84: if the first person called button3 (topic) published the signal(payload) of “1”, then ledPin3 HIGH (on). If signal(payload) of “0”, then ledPin3 LOW (off).

Line 85-94:  if the first person called button4 (topic) published the signal(payload) of “1”, then ledPin4 HIGH (on). If signal(payload) of “0”, then ledPin4 LOW (off).

Line 99: Loop through client

Line 101-103: Make WiFi and MQTT connect

Line 108: reads button value

Line 110-131: publish the signal of your “/button1" through. If button pressed send signal “1" and if button is pressed again send signal “0” and so on.

**Tab Connect**

Line 3-9: if ID and Pass is good then connect to WiFi

Line 11-19: if MQTT server and port and WiFi client (net) is correct and device, key and secret also then connect to MQTT broker

Line 21: connect with messageReceived

Line 23-26: Subscribe all the incoming signals from other people, so from button 1 till 4

# Explanation how publish and subscribe works

**Publish**

On line 118 and line 122 you see:
```
client.publish("/button1", “1");
client.publish("/button1", "0");
```

This tells you that you publish information to shiftr.io through MQTT network.

“/button1” tells you that this is you who sending the signal

“1" tells that you sending signal 1, what later will be set as LED being ON

“0" tells that you sending signal 0, what later will be set as LED being OFF

So if (buttonState == HIGH), so you clicked the button your sending from button 1 signal 1.

**Subscribe**

In tab Connect you see on line 23 till 26:

```
client.subscribe("/button1"); 

client.subscribe(“/button2");

client.subscribe("/button3");  

client.subscribe(“/button4");
```
This tells you that your able to subscribe the signals coming from shiftr.io, that early being send from others publishing as buttons 1 till 4 as seen above.

At the publish you see your button 1, but others are 2 till 4. And ofcourse later there can be more. 

**Who are you**

On line 53, 63, 73 and 83 you see in the function messageReceived:

```
if (topic == "/button1") {

if (topic == "/button2") {

if (topic == "/button3") {

if (topic == "/button4") {
```

This is saying if you receive a subscription from button 1 etc.

And what you see on line 54, 58, 64, 68, 74, 78, 84, 88:

```
if (payload == "1") {
else if (payload == "0") {
```

And the signal is 1, then turn the led HIGH (on) and if the signal is 0, then turn the led LOW (off)
