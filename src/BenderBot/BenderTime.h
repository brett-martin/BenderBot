/*!
 * @file BenderTime.h
 * 
 * This class handles displaying images and animations on 4x 16x8 matrix displays
 * These displays use I2C to communicate, 2 pins are required to
 * interface. There are multiple selectable I2C addresses. For backpacks
 * with 2 Address Select pins: 0x70, 0x71, 0x72, 0x73.
 */

#ifndef BenderTime_h
#define BenderTime_h

#include "Arduino.h"
#include "RTClib.h"


class BenderTime {
public:
  
    BenderTime();

    String getTime(void);

    int getTemp(void);


protected:
    uint8_t i2c_addr; ///< Device I2C address
    char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    RTC_DS3231 rtc;
};


#endif // BenderTime_h
