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
const char device[] = ""; // broker device identifier

// setting Wifi/MQTT
int status = WL_IDLE_STATUS;
WiFiClient net;
MQTTClient client;
unsigned long lastMillis = 0; // the last time the output pin was toggled

// setting buttonPin 
const int buttonPin = 4;
int buttonState = 0;
int buttonClick = 0;
int lastButtonClick = 0;

//LEDS (OUTPUT)
int ledPin1 = 0;

// check your connection with WiFi and MQTT broker
void connect();

//Setup the pinMode of the pin to INPUT or OUTPUT (change middle part)
void setup() {
  Serial.begin(115200); // to see serial monitor
  
  pinMode(ledPin1, OUTPUT); // LED 1
  pinMode(buttonPin, INPUT); // set buttonPin
  
  connect(); // setup void connect()
}

// Place for other functions of other sensors later

// Receive Messages you send
void messageReceived(String &topic, String &payload) {
    Serial.println("incoming: " + topic + " - "); // you see serial monitor
    if (topic == "/button1") {   // received buttonclick (INPUT) from Person 1
      if (payload == "1") { // if send value "1" in loop
        digitalWrite(ledPin1, HIGH); // Set above function - first LED ON (here you can put EVERY FUNCTION you want of an OUTPUT that needs to happen)
        Serial.println("ON1"); // you see serial monitor that's ON
      }
      else if (payload == "0") { // if send "0" in loop
        digitalWrite(ledPin1, LOW); // Set above function - first LED (OFF)
        Serial.println("OFF1"); // you see serial monitor that's OFF
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

  if (millis() - lastMillis > 1000) { // 1000 is the debounce time; increase if the output flickers
    lastMillis = millis(); // equal to

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
