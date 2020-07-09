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

#define ANTENNA_LED 10

class BenderDisplay {
public:
  
    BenderDisplay(int numSegments);

    void init();

    void setBrightness(uint8_t b);

    void writeDisplay();

    void clear();

protected:
    uint8_t i2c_addr; ///< Device I2C address

private:
     Adafruit_8x16matrix** _segments;
     int _numSegments = 1;
     byte _segmentAddresses[4] = {0x70, 0x71, 0x72, 0x73};
};


#endif // BenderDisplay_h
