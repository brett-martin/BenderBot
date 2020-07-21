/*******************************************************************
    BenderTime.cpp
    Brett Martin
    7/1/2020
    
    Wrapping class for RTClib to manage setting and getting time
    via a DS3231 RTC connected via I2C and Wire lib
********************************************************************/

#include "RTClib.h"
#include "BenderTime.h"

BenderTime::BenderTime() {
  init(); 
}

void BenderTime::init() {
  Serial.begin(57600);

   _rtc = new RTC_DS3231();

  Serial.println("Starting RTC");

  if (! _rtc->begin()) {
    Serial.println("Couldn't find RTC");
    //abort();
  }

  if (_rtc->lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    // _rtc->adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // _rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}

TimeArray BenderTime::getTimeArray() {
    // Get the time
    DateTime now = _rtc->now();
    int hours = now.hour();
    int minutes = now.minute();
    // Serial.printf("%d:%d",hours,minutes);

    // Convert the time to an array of ints[4] [h1,h2,m1,m2]
    struct TimeArray time;
    time.h1 = 0;
    time.h2 = 0;
    time.m1 = 0;
    time.m2 = 0;

    int digitsHr = 0;
    int digitsMin = 0;

    if (hours > 12) {
      hours -= 12;
      digitsHr = (int)log10(hours); 
      if (digitsHr == 1 ) {
        time.h1 = (int)(hours / pow(10, digitsHr));
      } 
    }
    time.h2 = hours % 10;     
    
    digitsMin = (int)log10(minutes); 
    if (digitsMin == 1 ) {
      time.m1 = (int)(minutes / pow(10, digitsMin)); 
    }
    time.m2 = minutes % 10;

    // Serial.printf("Sending %d %d %d %d", time.h1,time.h2,time.m1,time.m2);

    return time;
}

int BenderTime::getTime() {
  DateTime now = _rtc->now();
  return now.secondstime();
}

int BenderTime::getTemp() {
   return _rtc->getTemperature();
}

void BenderTime::setTime() {
   // TODO: Set the time on the RTC
}