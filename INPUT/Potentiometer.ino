const int potentiometerPin = A0;

void setup() {
   Serial.begin(9600);
}

void loop() {
  int potentiometer = analogRead(potentiometerPin);
  int mappedPotState = map(potentiometer, 0, 1024, 0, 360);
  Serial.println(mappedPotState);
  delay(20);
}
