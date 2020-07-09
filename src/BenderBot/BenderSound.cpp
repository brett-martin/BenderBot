/*******************************************************************
    BenderSound.cpp
    Brett Martin
    7/1/2020
    
    This class handles UART communication between the main board and
    the Adafruit Audio FX sound board
    This uses serial1 of the M4 express (PB16/PB17), (D0,D1) as TX/RX 
    and D5 (PA16) as the reset trigger. Other serial ports can be used
    but D0/D1 are the fastest on the M4.
********************************************************************/

#include "Adafruit_Soundboard.h"
#include "BenderSound.h"

BenderSound::BenderSound() {
  init();
}

void BenderSound::init() {
  Serial.println("Connecting to Adafruit Sound Board!");
  
  Serial1.begin(9600);

  Adafruit_Soundboard _sfx = Adafruit_Soundboard(&Serial1, NULL, SFX_RST);

  if (!_sfx.reset()) {
    Serial.println("Reset soundboard failed");
    while (1);
  }
  Serial.println("SFX board ready");

 // setVol(150);      // Reduce volume recursivly first
  _sfx.listFiles();  // Must call this for fileSize to work lol
}

void BenderSound::playSound(int sound) {
  Serial.println("Playing Sound");
  Serial.println(sound);
  
  if (_sfx->playTrack(sound)) {
    int trackLength = getLength();
    delay(trackLength);
  } else {
    Serial.println("Play Sound failed");
  }
}

void BenderSound::playNext() {
  if (_sfx->playTrack(_nextSound)) {
    int trackLength = getLength();
    delay(trackLength);
  }
  _nextSound++;
  if (_nextSound > _endSound) {
    _nextSound = _startSound;
  }
}

void BenderSound::setVol(int newVol) {
  Serial.println("Setting Volume");

  if (newVol == _currentVol){
    Serial.println("Volume Set");
    return;
  }
  
  if (newVol > MAX_VOL || newVol < MIN_VOL) {
    Serial.println("Volume out of range");
    return;
  }

  if (newVol < _currentVol) {
    Serial.println("Go Up");
    _currentVol = volDown();
    setVol(newVol);
  } else if (newVol > _currentVol) {
    Serial.println("Go Down");
    _currentVol = volUp();
    setVol(newVol);
  }
}

int BenderSound::volUp() {
      Serial.println("Vol up...");
      uint16_t v;
      if (! (v = _sfx->volUp()) ) {
        Serial.println("Failed to adjust");
      } else {
        Serial.print("Volume: "); Serial.println(v);
      }
      return(v);
}

int BenderSound::volDown() {
      Serial.println("Vol down...");
      uint16_t v;
      if (! (v=_sfx->volDown()) ) {
        Serial.println("Failed to adjust");
      } else { 
        Serial.print("Volume: "); 
        Serial.println(v);
      }
      return(v);
}

int BenderSound::getLength(void) {
      //Serial.print("Track size (bytes remaining/total): ");
      uint32_t remain, total;
      if (! _sfx->trackSize(&remain, &total) ) 
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
