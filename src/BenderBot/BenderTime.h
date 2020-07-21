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

// Struct to hold time in individual time digits by name (h1 h2 : m1 m2)
struct TimeArray { 
    int h1;
    int h2;
    int m1;
    int m2;
}; 


class BenderTime {

protected:
    
    enum daysOfTheWeek {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday} day;
    
    RTC_DS3231 *_rtc;           // DS3231 Real Time Clock object

public:
  
    BenderTime();               // Constructor

    void init();                // Init

    TimeArray getTimeArray();   // Returns the current time in an array of digits

    int getTime();              // Returns the current time in seconds

    int getTemp();              // Returns the current temp

    void setTime();
};


#endif // BenderTime_h
