/*******************************************************************
    ReadProgmem.h
    Brett Martin
    7/18/2020
    
    This class reads from PROGMEM 
********************************************************************/

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "Wprogram.h"
#endif

template <typename T> void ReadProgmem (const T * sce, T& dest) {
    memcpy_P (&dest, sce, sizeof (T));
}

template <typename T> T GetProgmem (const T * sce) {
    static T temp;
    memcpy_P (&temp, sce, sizeof (T));
    return temp;
}