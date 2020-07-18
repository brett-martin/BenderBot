/*******************************************************************
    ExpAngry.h
    Brett Martin
    7/9/2020
    
    Returns data to build a complete expression
********************************************************************/

#include <Arduino.h>

static const uint8_t PROGMEM
  ExpAngry[][16] = {
  { B00000000,
    B00111111,
    B01111111,
    B01111111,
    B11111111,
    B11111111,
    B11111100,
    B11111100,
    B11111100,
    B11111100,
    B11111111,
    B11111111,
    B01111111,
    B01111111,
    B00111111,
    B00000000 },
  { B00000000,
    B11111100,
    B11111110,
    B11111110,
    B11111111,
    B11111111,
    B00111111,
    B00111111,
    B00111111,
    B00111111,
    B11111111,
    B11111111,
    B11111110,
    B11111110,
    B11111100,
    B00000000 },
  { B00000000,
    B00111111,
    B01111111,
    B01111111,
    B11111111,
    B11111111,
    B11111100,
    B11111100,
    B11111100,
    B11111100,
    B11111111,
    B11111111,
    B01111111,
    B01111111,
    B00111111,
    B00000000 },
  { B00000000,
    B11111100,
    B11111110,
    B11111110,
    B11111111,
    B11111111,
    B00111111,
    B00111111,
    B00111111,
    B00111111,
    B11111111,
    B11111111,
    B11111110,
    B11111110,
    B11111100,
    B00000000 }};

class SimulatorClass {
   typedef struct SimulatorRecord
   {
      uint8_t iSensorNumber;
      unsigned long lTriggerTime;
      uint8_t iState;
   } SimulatorRecord;

  static const SimulatorRecord SimulatorQueue[28] PROGMEM ;

  SimulatorRecord PendingRecord;
};

