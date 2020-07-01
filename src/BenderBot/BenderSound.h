/*!
 * @file BenderDisplay.h
 * 
 * This class handles displaying images and animations on 4x 16x8 matrix displays
 * These displays use I2C to communicate, 2 pins are required to
 * interface. There are multiple selectable I2C addresses. For backpacks
 * with 2 Address Select pins: 0x70, 0x71, 0x72, 0x73.
 */

#ifndef BenderSound_h
#define BenderSound_h

#include "Arduino.h"
#include <Wire.h>
#include "Adafruit_Soundboard.h"

#define SFX_RST 5
#define MIN_VOL 0
#define MAX_VOL 204
#define scaleFactor 172265


class BenderSound {

public:
    BenderSound(void);
    void setVol(int newVol);
    int volUp(void);
    int volDown(void);
    int getLength(void);
    void playSound(void);

protected:
    uint8_t i2c_addr; ///< Device I2C address
    Adafruit_Soundboard sfx = Adafruit_Soundboard(&Serial1, NULL, SFX_RST);
    const int MIN_SOUND = 0;
    const int MAX_SOUND = 11;
    int currentVol = 204;
    int nextSound = 0;

private:
    // Array[uint8_t] segments;
};


#endif // BenderSound_h
