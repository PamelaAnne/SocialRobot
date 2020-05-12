const int pingPin = 7;

#include <SPI.h>
#include <Adafruit_VS1053.h>
#include <SD.h>

#define BREAKOUT_RESET  9      // VS1053 reset pin (output)
#define BREAKOUT_CS     10     // VS1053 chip select pin (output)
#define BREAKOUT_DCS    8      // VS1053 Data/command select pin (output)
#define SHIELD_RESET  -1      // VS1053 reset pin (unused!)
#define SHIELD_CS     7      // VS1053 chip select pin (output)
#define SHIELD_DCS    6      // VS1053 Data/command select pin (output)
#define CARDCS 4     // Card chip select pin
#define DREQ 3       // VS1053 Data request, ideally an Interrupt pin

#define PLAYBACK_TIME 7000 // @luis says change this if you want to play for a different amount of time

Adafruit_VS1053_FilePlayer musicPlayer = 
Adafruit_VS1053_FilePlayer(BREAKOUT_RESET, BREAKOUT_CS, BREAKOUT_DCS, DREQ, CARDCS);

long startedWhen = 0;
  
void setup() {
  Serial.begin(9600);
  pinMode(pingPin, INPUT);

  if (! musicPlayer.begin()) { // initialise the music player
     Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
     while (1);
  }
  
   if (!SD.begin(CARDCS)) {
    while (1);  // don't do anything more
  }

  musicPlayer.setVolume(20,20);
  musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);  // DREQ int
}
  
void loop() {

  int reading = digitalRead(pingPin);

  if ( (reading == HIGH) && musicPlayer.stopped() ){
    musicPlayer.startPlayingFile("/track005.mp3");
    startedWhen = millis();
    //musicPlayer.playFullFile("/track005s.mp3");
  }

  if(millis() > (startedWhen + PLAYBACK_TIME) ) {
    musicPlayer.stopPlaying();
  }
  
  delay(50);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

/// File listing helper
void printDirectory(File dir, int numTabs) {
   while(true) {
     
     File entry =  dir.openNextFile();
     if (! entry) {
       break;
     }
     for (uint8_t i=0; i<numTabs; i++) {
       Serial.print('\t');
     }
     Serial.print(entry.name());
     if (entry.isDirectory()) {
       Serial.println("/");
       printDirectory(entry, numTabs+1);
     } else {
       Serial.print("\t\t");
       Serial.println(entry.size(), DEC);
     }
     entry.close();
   }
}
