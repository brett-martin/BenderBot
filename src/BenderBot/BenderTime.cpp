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
  //Serial.begin(57600);

  #ifndef ESP8266
    while (!Serial); // wait for serial port to connect. Needed for native USB
  #endif

   _rtc = new RTC_DS3231();

  Serial.println("Starting RTC");

  if (! _rtc->begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    //abort();
  }

  if (_rtc->lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    _rtc->adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}

String BenderTime::getTime(void) {
    DateTime now = _rtc->now();
    String time = String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());
    return time;
}

int BenderTime::getTemp(void) {
   return _rtc->getTemperature();
}