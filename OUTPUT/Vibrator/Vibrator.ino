const int VibratorPin = 6;

void setup() {
  pinMode(VibratorPin, OUTPUT);
}

void loop() {
  int VibratorStatus = analogRead(VibratorPin);
  if (){
    digitalWrite(VibratorStatus, HIGH);
  } else{
    digitalWrite(VibratorStatus, LOW);
  }
}
