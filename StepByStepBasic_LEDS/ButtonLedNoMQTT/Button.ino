// setting buttonPin 
const int buttonPin = 4;
int buttonClick = 0;

//LEDS (OUTPUT)
int ledPin1 = 0;

//Setup the pinMode of the pin to INPUT or OUTPUT (change middle part)
void setup() {
  Serial.begin(9600); // to see serial monitor
  pinMode(ledPin1, OUTPUT);
  pinMode(buttonPin, INPUT); // set buttonPin
}
   
// Send Messages
void loop() {
  int buttonClick = digitalRead(buttonPin); //digitalRead your button value HIGH or LOW

  if (buttonClick == HIGH) {
    digitalWrite(ledPin1, HIGH);
    Serial.print(buttonClick);
  } else {
    digitalWrite(ledPin1, LOW);
    Serial.print(buttonClick);
  }
}
