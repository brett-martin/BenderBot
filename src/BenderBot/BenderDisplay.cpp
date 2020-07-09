/*******************************************************************
    BenderDisplay.cpp
    Brett Martin
    7/1/2020
    
    This class handles displaying images and animations on 4x 16x8 matrix displays
    These displays use I2C to communicate, 2 pins are required to
    interface. There are multiple selectable I2C addresses. For backpacks
    with 2 Address Select pins: 0x70, 0x71, 0x72, 0x73.
********************************************************************/

#include "BenderDisplay.h"

#ifndef _BV
#define _BV(bit) (1 << (bit)) ///< Bit-value if not defined by Arduino
#endif

#ifndef _swap_int16_t
#define _swap_int16_t(a, b)                                                    \
  {                                                                            \
    int16_t t = a;                                                             \
    a = b;                                                                     \
    b = t;                                                                     \
  } ///< 16-bit var swap
#endif


BenderDisplay::BenderDisplay(int numSegments) {
  _numSegments = numSegments;
  init();
}

void BenderDisplay::init() {
  _segments = new Adafruit_8x16matrix*[_numSegments];
  for (int i = 0; i < _numSegments; i++) {
    Adafruit_8x16matrix *m = new Adafruit_8x16matrix();
    _segments[i] = m;
    _segments[i]->begin(_segmentAddresses[i]); 
  }
}

void BenderDisplay::setBrightness(uint8_t b) {
  // TODO: Set Brightness
}

void BenderDisplay::writeDisplay() {
  for (int i = 0; i < _numSegments; i++) {
    _segments[i]->drawRect(0,0, 8,16, LED_ON);
    _segments[i]->fillRect(2,2, 4,12, LED_ON);
    _segments[i]->writeDisplay();  // write the changes we just made to the display
  }
}

void BenderDisplay::clear() {
  for (int i = 0; i < _numSegments; i++) {
    _segments[i]->clear();
    _segments[i]->writeDisplay();
  }
}

