/*
UART communication test for M4 Express to Audio FX board
This uses serial1 of the M4 express (PB16/PB17), (D0,D1) as TX/RX and D5 (PA16) as the reset trigger

*/

//#include <Arduino.h>
#include "Adafruit_Soundboard.h"
#include "BenderSound.h"

BenderSound::BenderSound(void) {
  
  // No idea why I dont see this output in the serial monitor??
  Serial.begin(115200);
  Serial.println("Adafruit Sound Board!");
  
  Serial1.begin(9600);

  if (!sfx.reset()) {
    Serial.println("Reset Not found");
    while (1);
  }
  Serial.println("SFX board found");

  setVol(150); // Reduce volume recursivly first
  sfx.listFiles(); // Must call this for fileSize to work lol
}

void BenderSound::playSound(void) {
    if (sfx.playTrack(nextSound)) {
      int trackLength = getLength();
      delay(trackLength);
    }
   nextSound++;
   if (nextSound > MAX_SOUND) {
    nextSound = MIN_SOUND;
   }
}

void BenderSound::setVol(int newVol) {
  Serial.println("Setting Volume");

  if (newVol == currentVol){
    Serial.println("Volume Set");
    return;
  }
  
  if (newVol > MAX_VOL || newVol < MIN_VOL) {
    Serial.println("Volume out of range");
    return;
  }

  if (newVol < currentVol) {
    Serial.println("Go Up");
    currentVol = volDown();
    setVol(newVol);
  } else if (newVol > currentVol) {
    Serial.println("Go Down");
    currentVol = volUp();
    setVol(newVol);
  }
}

// Try to turn the volume Up and then return the current volume
int BenderSound::volUp(void) {
      Serial.println("Vol up...");
      uint16_t v;
      if (! (v = sfx.volUp()) ) {
        Serial.println("Failed to adjust");
      } else {
        Serial.print("Volume: "); Serial.println(v);
      }
      return(v);
}

// Try to turn the volume Down and then return the current volume
int BenderSound::volDown(void) {
      Serial.println("Vol down...");
      uint16_t v;
      if (! (v=sfx.volDown()) ) {
        Serial.println("Failed to adjust");
      } else { 
        Serial.print("Volume: "); 
        Serial.println(v);
      }
      return(v);
}


// Get the size in bytes and return estimated seconds the track is long so we can use for a delay
int BenderSound::getLength(void) {
      //Serial.print("Track size (bytes remaining/total): ");
      uint32_t remain, total;
      if (! sfx.trackSize(&remain, &total) ) 
        Serial.println("Failed to query");
      //Serial.print(remain); Serial.print("/"); Serial.println(total); 
      //int r = total/scaleFactor;
      //Serial.println("Estimated Seconds total");
      //Serial.print(r);
      int r2 = remain/scaleFactor;
      //Serial.println("Estimated Seconds remain");
      //Serial.print(r2);
      return max(r2 * 1000, 1000);
}
