/*******************************************************************
    Bender.cpp
    Brett Martin
    7/1/2020
    
    Wrapping class for all Bender functions and classes into a single
    Bender class.
********************************************************************/

#include "Bender.h"


Bender::Bender() {
    init();
}

void Bender::init() {
    _antenna = new Led(13);
    _button = new Button(19); 
    _clock = new BenderTime();
}

bool Bender::buttonPushed(int b) {
    switch (b)
    {
    case 1:
        return _button->wasPressed();
        break;
    
    default:
        break;
    }
    return false;
}

void Bender::antennaOn(byte state) {
    if (state)
         _antenna->on(1000);
    else
         _antenna->off();
}

void Bender::showClock() {
    String t = _clock->getTime();
    Serial.println("Time is ");
    Serial.println(t);
}
