/*******************************************************************
    Main.cpp
    Brett Martin
    7/1/2020
    
    App to interact with and control Bender hardware
********************************************************************/

#include <Arduino.h>

#include "BenderBot/Bender.h"

Bender *bender; 
int _currentTime = 0;
int _newTime = 0;
void setup() { 
  Serial.begin(115200);
  bender = new Bender();
}

void loop() {
  _newTime = bender->getTime();
  //Serial.printf("T:%d\n", _newTime);

  if (bender->buttonPushed(1) == true) {
    bender->antennaOn(true);
    bender->playAnimation("Angry");
  } else if ( _newTime > _currentTime + 20) {
    Serial.println("Updating Clock");
    _currentTime = _newTime;
    bender->showClock();
  }

  if (bender->buttonPushed(2) == true) {
    bender->say(3);
  }

  if (bender->buttonPushed(3) == true) {
    Serial.println("Updating Clock");
    bender->showClock();
  }

  if (bender->buttonPushed(4) == true) {
    bender->say(13);
  }

  if (bender->buttonPushed(5) == true) {
    bender->displayOn(false);
  }
}