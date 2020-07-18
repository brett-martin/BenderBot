/*******************************************************************
    BenderExpressions.h
    Brett Martin
    7/9/2020
    
    This class initializes all of the bender expressions making them
    available in a single class
********************************************************************/

#ifndef BenderExpressions_h
#define BenderExpressions_h

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "Wprogram.h"
#endif

#include "Expressions/ExpAngry.h"


class BenderExpressions {

public:
  
    BenderExpressions();

    void init();

    // ExpAngry* getExpression();

private:
    // ExpAngry *_angry;

};


#endif // BenderExpressions_h
