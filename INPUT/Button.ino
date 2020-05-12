const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  5;      // the number of the LED pin

int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.print(buttonState);
  } else {
    digitalWrite(ledPin, LOW);
    Serial.print(buttonState);
  }
}
