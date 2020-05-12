// Include WiFi & MQTT Library
#include <WiFiNINA.h> // import WiFiNINA library (Sketch --> Use Library --> Manage Library --> search and install)
#include <MQTT.h> // import adafruit MQTT library (Sketch --> Use Library --> Manage Library --> search and install)

// "" set your wifi name and password + broker key and secret of shiftr.io. Device name you see on shiftr.io coming up.
const char WIFI_SSID[] = ""; // WiFI ssid
const char WIFI_PASS[] = ""; //WiFI password
const char mqttServer[] = "broker.shiftr.io"; // broker, with shiftr.io it's "broker.shiftr.io"
const int mqttServerPort = 1883; // broker mqtt port
const char key[] = ""; // broker key
const char secret[] = ""; // broker secret
const char device[] = "ArduinoPerson"; // broker device identifier

// setting Wifi/MQTT
int status = WL_IDLE_STATUS;
WiFiClient net;
MQTTClient client;
unsigned long lastMillis = 0;

// setting buttonPin 
const int buttonPin = 4;
int buttonState = 0;
int buttonClick = 0;
int lastButtonClick = 0;

// setting button2Pin
const int button2Pin = 2;
int button2PushCounter = 0;   // counter for the number of button presses
int button2State = 0;         // current state of the button
int lastButton2State = 0;     // previous state of the button

// settings LEDstrip
#include <Adafruit_NeoPixel.h> // import LED strip library
#ifdef __AVR__Basic
  #include <avr/power.h>
#endif
#define PIN 4 // Pin LED strip
int numLEDS = 4; // Amount of LEDs on your strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLEDS, PIN, NEO_GRB + NEO_KHZ800);

// check your connection with WiFi and MQTT broker
void connect();

//Setup the pinMode of the pin to INPUT or OUTPUT (change middle part)
void setup() {
  Serial.begin(115200); // to see serial monitor
  
  strip.begin(); // begin LEDStrip
  strip.setBrightness(30); // set brightness LEDStrip
  strip.show(); // show LEDStrip
  
  pinMode(buttonPin, INPUT); // set buttonPin
  pinMode(button2Pin, INPUT); // set button2Pin

  connect(); // setup void connect()
}

// Place for other functions of other sensors later
void setLedStrip();

// Receive Messages you send
void messageReceived(String &topic, String &payload) {
    Serial.println("incoming: " + topic + " - "); // you see serial monitor
    if (topic == "/button1") {   // received buttonclick (INPUT) from Person 1
      if (payload == "1") { // if send value "1" in loop
        setLedStrip(0, 255, 0, 0); // Set above function - first LED ON Red(here you can put EVERY FUNCTION you want of an OUTPUT that needs to happen)
        Serial.println("ON1"); // you see serial monitor that's ON
      }
      else if (payload == "2") { 
        setLedStrip(0, 0, 0, 255); 
        Serial.println("ON1Blue"); 
      }
      else if (payload == "3") { 
        setLedStrip(0, 0, 255, 0); 
        Serial.println("ON1Green"); 
      }
      else if (payload == "4") { 
        setLedStrip(0, 255, 0, 0); 
        Serial.println("ON1Red"); 
      }
      else if (payload == "0") { // if send "0" in loop
        setLedStrip(0, 0, 0, 0); // Set above function - first LED (OFF)
        Serial.println("OFF1"); // you see serial monitor that's OFF
      }
    }
    if (topic == "/button2") {  // Person 2
      if (payload == "1") {
        setLedStrip(1, 255, 0, 0);
        Serial.println("ON2");
      }
      else if (payload == "2") { 
        setLedStrip(1, 0, 0, 255); 
        Serial.println("ON2Blue"); 
      }
      else if (payload == "3") { 
        setLedStrip(1, 0, 255, 0); 
        Serial.println("ON2Green"); 
      }
      else if (payload == "4") { 
        setLedStrip(1, 255, 0, 0); 
        Serial.println("ON2Red"); 
      }
      else if (payload == "0") {
        setLedStrip(1, 0, 0, 0);
        Serial.println("OFF2");
      }
    }
    if (topic == "/button3") {  // Person 3
      if (payload == "1") {
        setLedStrip(2, 255, 0, 0);
        Serial.println("ON3");
      }
      else if (payload == "2") { 
        setLedStrip(2, 0, 0, 255); 
        Serial.println("ON3Blue"); 
      }
      else if (payload == "3") { 
        setLedStrip(2, 0, 255, 0); 
        Serial.println("ON3Green"); 
      }
      else if (payload == "4") { 
        setLedStrip(2, 255, 0, 0); 
        Serial.println("ON3Red"); 
      }
      else if (payload == "0") {
        setLedStrip(2, 0, 0, 0);
        Serial.println("OFF3");
      }
    }
    if (topic == "/button4") {  // Person 4
      if (payload == "1") {
        setLedStrip(3, 255, 0, 0);
        Serial.println("ON4");
      }
      else if (payload == "2") { 
        setLedStrip(3, 0, 0, 255); 
        Serial.println("ON4Blue"); 
      }
      else if (payload == "3") { 
        setLedStrip(3, 0, 255, 0); 
        Serial.println("ON4Green"); 
      }
      else if (payload == "4") { 
        setLedStrip(3, 255, 0, 0); 
        Serial.println("ON4Red"); 
      }
      else if (payload == "0") {
        setLedStrip(3, 0, 0, 0);
        Serial.println("OFF4");
      }
    }   
}
   
// Send Messages
void loop() {
  client.loop(); // loop through WiFi/MQTT client

  if (!net.connected()) { // connect
    connect();
  }

  // @CHANGE
  // Reading the value of the button and set it as variable buttonState
  // Also can be another INPUT that you read as LDR, Acceloremeter, switch etc.
  int buttonClick = digitalRead(buttonPin); //digitalRead your button value HIGH or LOW
  int button2State = digitalRead(button2Pin); //digitalRead your button2State
  
  if (millis() - lastMillis > 1000) { 
    lastMillis = millis(); // equal to

    //Button 2
    if (button2State != lastButton2State) { // isn't equal 
        if (button2State == HIGH) { // if button2 is pressed
          button2PushCounter++; // put the counter of button2 +1
          Serial1.println("on");
          Serial1.print("number of button pushes: ");
          Serial1.println(button2PushCounter);
        } else {
          Serial1.println("off");
        }
        delay(50);
    }
    lastButton2State = button2State; // equal to

    if (buttonState == HIGH){ // Button1 is ON
      if (button2PushCounter == 1){ // Button2 pressed 1 time
         client.publish("/button1", "2");  // client /button1 sending value "2"
         Serial1.println("2");
      }  
      else if (button2PushCounter == 2){ // Button2 pressed 2 time
         client.publish("/button1", "3"); // client /button1 sending value "3"
         Serial1.println("3");
      } 
      else if (button2PushCounter == 3){ // Button2 pressed 3 time
         client.publish("/button1", "4"); // client /button1 sending value "4"
         Serial1.println("4");
      } 
      else if (button2PushCounter >= 4){ // Button2 pressed 4 or more times
         button2PushCounter = 0; // setting counter back to zero
      }
    }

    //Button 1    
    if (buttonClick != lastButtonClick) { // isn't equal   
      if (buttonClick == 1) {
        buttonState = !buttonState; // opposite of buttonState        
        if (buttonState == HIGH){ // if button pressed    //at which VALUE (HIGH, LOW, Numbers) of the INPUT WHAT does it need to do
          client.publish("/button1", "1"); // client /button1 (Let that be your signal) sending value "1" (this can go further to 2, 3, 4 etc.) 
          Serial.println("1"); // you see serial monitor
          Serial.println("clicked");
        } else{ // if button not pressed
          client.publish("/button1", "0"); // client /button1 send value "0"
          Serial.println("0"); // you see serial monitor
        }  
        delay(50); // wait for a moment
      }
      lastButtonClick = buttonClick; // equal to
    }
    
    lastMillis = millis(); // equal to
  }
}
