/*******************************************************************
    Bender.cpp
    Brett Martin
    7/1/2020
    
    Wrapping class for all Bender functions and classes into a single
    Bender class.
********************************************************************/

#include "Bender.h"

Bender::Bender(int antennaPin, int buttonPin) : _antenna (antennaPin), _button (buttonPin)  { 
    init();
}

void Bender::init() {
    // Nothing yet
}

bool Bender::buttonPushed(int b) {
    switch (b)
    {
    case 1:
        return _button.wasPressed();
        break;
    
    default:
        break;
    }
    return false;
}

void Bender::antennaOn(byte state) {
    if (state)
         _antenna.on(1000);
    else
         _antenna.off();
}
