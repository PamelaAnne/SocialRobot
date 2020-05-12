#define BUTTON_PIN 4

int btnState;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
//  pinMode(BUTTON_PIN, INPUT);
//  digitalWrite(BUTTON_PIN, HIGH);
}

void loop() {
  btnState = digitalRead(BUTTON_PIN);
  digitalWrite(13, btnState);
}
