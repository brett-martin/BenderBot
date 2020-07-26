/*******************************************************************
    BenderDisplay.h
    Brett Martin
    7/1/2020
    
    This class handles displaying images and animations on 4x 16x8 matrix displays
    These displays use I2C to communicate, 2 pins are required to
    interface. There are multiple selectable I2C addresses. For backpacks
    with 2 Address Select pins: 0x70, 0x71, 0x72, 0x73.
********************************************************************/

#ifndef BenderDisplay_h
#define BenderDisplay_h

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "Wprogram.h"
#endif

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
#include "Adafruit_LEDBackpack.h" // Generates warning messages, why?
#include "BenderAnimations.h"
#include "Numbers.h"
#include "Led.h"

const int COLON_LED = 11;

class BenderDisplay {
public:
  
    BenderDisplay(int numSegments, uint8_t brightness); // Setup the display

    void init();                                        // Init

    void setBrightness(uint8_t b);                      // Set brightness 0-15

    void writeDisplay();                                // Re-draw the display

    void clear();                                       // Clear the display

    void showExpression(ExpressionNames name);                              // Show an expression spanning all segments

    void showNumber(int number, int segment);           // Show a single digit on a single segment

    void colonOn(bool state);                           // Turns on the colon for displaying time

    void blinkColon();

private:
     Adafruit_8x16matrix** _segments;                   // Pointer to array of 8x16 segments

     int _numSegments = 1;                              // Holds number of segments in display

     uint8_t _brightness = 2;                           // Holds current brightness

     byte _segmentAddresses[4] = {0x70, 0x71, 0x72, 0x73}; // Addresses for possible segments

     Led *_colon;                                       // Controls the colon LEDs
};


#endif // BenderDisplay_h
