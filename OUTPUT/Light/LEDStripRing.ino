#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN 6

//int numLEDS = 20; // LEDStrip
int numLEDS = 24; //LEDRing

Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLEDS, PIN, NEO_GRB + NEO_KHZ800); //LEDRing
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLEDS, PIN, NEO_RGBW + NEO_KHZ800); // LEDStrip

void setup() {
  Serial.begin(9600);

  strip.begin();
  strip.setBrightness(30); 
  strip.show();
}

void loop() {
//  if () {
    turnOnRed();
//  }
//  else if () {
//    turnOnBlue();
//  }
//  else{
//    turnOff();
//  }
}

void turnOnRed() {
  Serial.println("Lamp On");
//  for(int i=0; i<24; i++) { // LEDRing
  for(uint16_t i=0; i<24; i++) { // LEDStrip
    strip.setPixelColor(i, strip.Color(255, 0, 0));
    strip.show();
    delay(50);   
  }
}

void turnOnBlue() {
  Serial.println("Lamp On");
//  for(int i=0; i<24; i++) { // LEDRing
  for(uint16_t i=0; i<20; i++) { // LEDStrip
    strip.setPixelColor(i, strip.Color(0, 0, 255));
    strip.show();
    delay(50);   
  }
}

void turnOff() {
  Serial.println("Lamp Off");
//  for(int i=0; i<24; i++) { // LEDRing
  for(uint16_t i=0; i<20; i++) { // LEDStrip
    strip.setPixelColor(i, strip.Color(0, 0, 0));
    strip.show();
    delay(50);   
  }
}
