/*******************************************************************
    BenderTime.cpp
    Brett Martin
    7/1/2020
    
    Wrapping class for RTClib to manage setting and getting time
    via a DS3231 RTC connected via I2C and Wire lib
********************************************************************/

#include "RTClib.h"
#include "BenderTime.h"
#include <time.h>

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
  _rtc->writeSqwPinMode(DS3231_SquareWave1Hz); // Tell RTC to output a 1hz pulse from it's output so we can use it to update the time ever second
}

int BenderTime::getTime() {
  // Get the time
  DateTime now = _rtc->now();
  int hours = now.hour();
  int minutes = now.minute();
  int time = hours*100 + minutes;

  // Serial.printf("%d:%d",hours,minutes);
  // Serial.print(time);
  // TODO: add 12/24 hr check here
  // convert 24hr rtc to 12hr time
  if (hours > 12) {
  time -= 1200;
  }

  // Convert Midnight to 1200
  if (hours == 0) {
    time += 1200;
  }

  return time;
}

int BenderTime::getSeconds() {
  DateTime now = _rtc->now();
  return now.secondstime();
}

int BenderTime::getTemp() {
   return _rtc->getTemperature();
}

void BenderTime::setTime() {
   // TODO: Set the time on the RTC
}