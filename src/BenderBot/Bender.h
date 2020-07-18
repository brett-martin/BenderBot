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
#include "BenderTime.h"
#include "BenderDisplay.h"
#include "BenderSound.h"

class Bender {

private:
    Led *_antenna;              // antenna Led object

    Button *_buttonRed;         // button input object

    Button *_buttonYellow;      // button input object

    Button *_buttonGreen;       // button input object

    Button *_buttonBlue;        // button input object

    Button *_buttonWhite;       // button input object
    
    BenderTime *_clock;         // Clock object

    BenderDisplay *_display;    // Display object

    BenderSound *_mouth;        // Sound object

public:

    Bender();                   // Constructor including constructor vars for included classes

    void init();                // Init

    bool buttonPushed(int b);   // Checks to see if the button was pushed recently

    void antennaOn(byte state); // Turn on the antenna

    void showClock();           // Display the time on the LED screen

    void say(int sound);        // Play a sound file # x

    void displayOn(bool state); // Turn display on or off

    void showExpression(String expression);
    
    void playAnimation(String animation);

    int getTime();

};
#endif