/*!
 * @file BenderDisplay.cpp
 * 
 * This class handles displaying images and animations on 4x 16x8 matrix displays
 * These displays use I2C to communicate, 2 pins are required to
 * interface. There are multiple selectable I2C addresses. For backpacks
 * with 2 Address Select pins: 0x70, 0x71, 0x72, 0x73.
 */

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


void BenderDisplay::setBrightness(uint8_t b) {
  // Set Brightness
}

BenderDisplay::BenderDisplay(void) {}


void BenderDisplay::writeDisplay(void) {
  // Update display
}

void BenderDisplay::clear(void) {
  // Clear
}

