/*!
 * @file BenderDisplay.h
 * 
 * This class handles displaying images and animations on 4x 16x8 matrix displays
 * These displays use I2C to communicate, 2 pins are required to
 * interface. There are multiple selectable I2C addresses. For backpacks
 * with 2 Address Select pins: 0x70, 0x71, 0x72, 0x73.
 */

#ifndef BenderDisplay_h
#define BenderDisplay_h

#include "Arduino.h"
#include <Wire.h>

#define ANTENNA_LED 10

class BenderDisplay {
public:
  
    BenderDisplay(void);

    void setBrightness(uint8_t b);

    void writeDisplay(void);

    void clear(void);

protected:
    uint8_t i2c_addr; ///< Device I2C address
private:
    // Array[uint8_t] segments;
};


#endif // BenderDisplay_h
