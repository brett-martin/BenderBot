/*******************************************************************
    BenderTime.h
    Brett Martin
    7/1/2020
    
    Wrapping class for RTClib to manage setting and getting time
    via a DS3231 RTC connected via I2C and Wire lib
********************************************************************/

#ifndef BenderTime_h
#define BenderTime_h

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "Wprogram.h"
#endif

#include "RTClib.h"


class BenderTime {

protected:
    
    char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
    RTC_DS3231 *_rtc;

public:
  
    BenderTime();

    void init();

    String getTime(void);

    int getTemp(void);
};


#endif // BenderTime_h
