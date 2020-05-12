// Functions
void setLedStrip(int ledPixel, int redValue, int greenValue, int blueValue) {
    strip.setPixelColor(ledPixel, strip.Color(redValue, greenValue, blueValue)); // set LED
    strip.show();
    delay(50);   
}
