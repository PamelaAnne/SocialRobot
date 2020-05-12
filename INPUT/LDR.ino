const int ldrPin = A1;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ldrPin, INPUT);
}

void loop() {
  int ldrStatus = analogRead(ldrPin);
  
  if (ldrStatus <= 600) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print("Its DARK ");
    Serial.println(ldrStatus);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    Serial.print("Its BRIGHT ");
    Serial.println(ldrStatus);
  }
}
