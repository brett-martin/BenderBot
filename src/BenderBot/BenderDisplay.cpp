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


BenderDisplay::BenderDisplay(int numSegments, uint8_t brightness) {
  _numSegments = numSegments;
  _brightness = brightness;
  init();
}

void BenderDisplay::init() {
  _segments = new Adafruit_8x16matrix*[_numSegments];
  _colon = new Led(COLON_LED);

  for (int i = 0; i < _numSegments; i++) {
    Adafruit_8x16matrix *m = new Adafruit_8x16matrix();
    _segments[i] = m;
    _segments[i]->begin(_segmentAddresses[i]); 
  }

  setBrightness(_brightness);
}

void BenderDisplay::setBrightness(uint8_t value) { // 0-15
  for (int i = 0; i < _numSegments; i++) {
    _segments[i]->setBrightness(value);
  }
}

void BenderDisplay::writeDisplay() {
  for (int i = 0; i < _numSegments; i++) {
    _segments[i]->writeDisplay();
  }
}

void BenderDisplay::clear() {
  for (int i = 0; i < _numSegments; i++) {
    _segments[i]->clear();
    _segments[i]->writeDisplay();
  }
}

void BenderDisplay::showExpression(ExpressionNames name) {
    colonOn(false);
    clear();
    _segments[0]->drawBitmap(0, 0, Expressions[name][0], 8, 16, LED_ON);
    _segments[1]->drawBitmap(0, 0, Expressions[name][1], 8, 16, LED_ON);
    _segments[2]->drawBitmap(0, 0, Expressions[name][2], 8, 16, LED_ON);
    _segments[3]->drawBitmap(0, 0, Expressions[name][3], 8, 16, LED_ON);
  
    writeDisplay();
}

void BenderDisplay::showNumber(int number, int segment) {
 _segments[segment]->drawBitmap(0, 0, Numbers[number], 8, 16, LED_ON);
}

void BenderDisplay::colonOn(bool state) {
  if (state) {
    _colon->on();
  } else {
    _colon->off();
  }
}

