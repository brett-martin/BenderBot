/*******************************************************************
    Main.cpp
    Brett Martin
    7/1/2020
    
    App to interact with and control Bender hardware
********************************************************************/

#include <Arduino.h>

#include "BenderBot/Bender.h"

Bender *bender; 
int _ticks = 0;
int _previousTick = 0;
const int _clockPin = 12; // pin used as input from RTC square wave output

void clockTick() {      // Increments the tick counter +1 each time the _clockPin is triggered @1hz by the RTC (every 1 second)
  _ticks++;
}

void setup() { 
  Serial.begin(115200);
  bender = new Bender();
  pinMode(_clockPin,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(_clockPin), clockTick, FALLING);
}

void loop() {

  if (_ticks != _previousTick) { // Update the clock if 1 second has passed.
    _previousTick = _ticks;
    bender->showClock();
    bender->blinkColon();
  }

  if (bender->buttonPushed(1) == true) {
    bender->antennaOn(true);
    bender->playAnimation(AngryAni);
  }

  if (bender->buttonPushed(2) == true) {
    bender->say(1);
  }

  if (bender->buttonPushed(3) == true) {
    bender->showClock();
  }

  if (bender->buttonPushed(4) == true) {
    bender->say(13);
  }

  if (bender->buttonPushed(5) == true) {
    bender->displayOn(false);
  }
}