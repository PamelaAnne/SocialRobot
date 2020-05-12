// **Wiring by uploading on board:**
//GND - GND
//5V - 5V

//**To put on the screen:**
//GND - GND
//5V - 5V
//Tx - Rx
//Rx- Tx

//Always end with Serial.println(); with the screen code

const int button2Pin = 5;
// button 2
int button2PushCounter = 0;   // counter for the number of button presses
int button2State = 0;         // current state of the button
int lastButton2State = 0;     // previous state of the button

void setup() {
  Serial1.begin(9600); // to see serial monitor - Serial1 for LCD Screen Tx/Rx
  pinMode(button2Pin, INPUT);
}

// Functions
void FaceSad();
void FaceSuprised();
void FaceOkay();
void FaceHappy();
void FaceOff();

void loop() {  
  int button2State = digitalRead(button2Pin);
  
  if (button2State != lastButton2State) {
        if (button2State == HIGH) {
          button2PushCounter++;
          Serial1.println("on");
          Serial1.print("number of button pushes: ");
          Serial1.println(button2PushCounter);
        } else {
          Serial1.println("off");
        }
        delay(50);
  }
  lastButton2State = button2State;

  if (button2PushCounter == 1){
    FaceSad();
  }
  else if(button2PushCounter == 2){
    FaceSuprised();
  }
  else if(button2PushCounter == 3){
    FaceOkay();
  }
  else if(button2PushCounter == 3){
    FaceHappy();
  }
  else if(button2PushCounter >= 4){
    button2PushCounter = 0;
    FaceOff();
  }
}
