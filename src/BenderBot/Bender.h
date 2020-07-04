/*******************************************************************
    Bender.h
    Brett Martin
    7/1/2020
    
    Wrapping class for all Bender functions and classes
********************************************************************/

#ifndef Bender_h
#define Bender_h

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "Wprogram.h"
#endif

#include "Led.h"
#include "Button.h"
//#include "BenderTime.h"


class Bender {

private:
    Led *_antenna;           // antenna Led object

    Button *_button;         // button input object
    
    //BenderTime _clock;      // Clock object

public:

    Bender(); // Constructor including constructor vars for included classes

    void init();            // Init

    bool buttonPushed(int b);     // Turn on the antenna when the button is pushed

    void antennaOn(byte state);

    void showClock();
};

#endif