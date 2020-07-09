/*******************************************************************
    Main.cpp
    Brett Martin
    7/1/2020
    
    App to interact with and control Bender hardware
********************************************************************/

#include <Arduino.h>

#include "BenderBot/Bender.h"

Bender *bender; 

void setup() { 
  Serial.begin(115200);
  bender = new Bender();
}

void loop() {
  if (bender->buttonPushed(1) == true) {
    bender->antennaOn(true);
    Serial.println("Antenna On");
    bender->showClock();
    bender->say(3);
  }
}
