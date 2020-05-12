// A0 - Yellow
// White nothing
// Red - 5V
// Black - Ground

#include <math.h>
#define LIGHT_SENSOR A0 //Grove - Light Sensor is connected to A0 of Arduino
const int thresholdvalue = 10; //The threshold for which the LED should turn on.
float Rsensor; //Resistance of sensor in K

void setup() {
  Serial.begin(9600); //Start the Serial connection
  pinMode(LED_BUILTIN, OUTPUT);

}
void loop() {
  int sensorValue = analogRead(LIGHT_SENSOR);
  Rsensor = (float)(1023-sensorValue) * 10/sensorValue;
  
  if (Rsensor > thresholdvalue){
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  
  Serial.println("the analog read data is ");
  Serial.println(sensorValue);
  Serial.println("the sensor resistance is ");
  Serial.println(Rsensor, DEC);//show the light intensity on the serial monitor;
  delay(1000);
}
