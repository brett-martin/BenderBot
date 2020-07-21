/*******************************************************************
    BenderAnimations.h
    Brett Martin
    7/18/2020
    
    This class initializes all of the bender animations making them
    available in a single class
********************************************************************/

#ifndef BenderAnimations_h
#define BenderAnimations_h

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "Wprogram.h"
#endif

#include "BenderExpressions.h"


enum AnimationNames {AngryAni};

struct AnimationStep {
    ExpressionNames exp;
    int waitTime;
};

struct Animation {
    AnimationStep steps[10];
    int audio;
};

static const Animation AniAngry = {
    {{Neutral,200},
    {SemiAngry,200},
    {Angry,200},
    {VeryAngry,200},
    {Angry,200},
    {SemiAngry,200},
    {Neutral,200}
    }, 3};

#endif // BenderAnimations_h
