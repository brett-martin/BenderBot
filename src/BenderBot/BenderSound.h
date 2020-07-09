/*******************************************************************
    BenderSound.h
    Brett Martin
    7/1/2020
    
    This class handles UART communication between the main board and
    the Adafruit Audio FX sound board
    This uses serial1 of the M4 express (PB16/PB17), (D0,D1) as TX/RX 
    and D5 (PA16) as the reset trigger. Other serial ports can be used
    but D0/D1 are the fastest on the M4.
********************************************************************/

#ifndef BenderSound_h
#define BenderSound_h

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "Wprogram.h"
#endif

#include <Wire.h>
#include "Adafruit_Soundboard.h"

#define SFX_RST 5
#define MIN_VOL 0
#define MAX_VOL 204
#define scaleFactor 172265


class BenderSound {

public:
    BenderSound();

    void init();

    void setVol(int newVol);    // Set a new volume between min and max volume

    int volUp();                // Try to turn the volume Up and then return the current volume
    
    int volDown();              // Try to turn the volume Down and then return the current volume
    
    int getLength();            // Get the size in bytes and return estimated seconds the track is long so we can use for a delay
    
    void playSound(int sound);

    void playNext();


private:

    Adafruit_Soundboard *_sfx;  // Soundboard object
    
    const int _startSound = 0;  // Start at sound # 0
    
    const int _endSound = 11;   // Total number of songs loaded on the board
    
    int _nextSound = 0;         // Holds "current" song when looping through songs

    const int _minVol = 0;      // Min volume of the board is 0

    const int _maxVol = 204;    // Max volume of the board is 204

    int _currentVol = 204;      // Board always starts at max volume and volume must be set
};


#endif // BenderSound_h
