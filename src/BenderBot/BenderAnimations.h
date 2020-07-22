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

struct AnimationFrame {
    ExpressionNames exp;
    int waitTime;
};

struct Animation {
    AnimationFrame frames[10];
    int audio;
};

static const Animation AniAngry = {
    {{Neutral,400},
    {SemiAngry,600},
    {Angry,600},
    {VeryAngry,800},
    {Angry,100},
    {SemiAngry,100},
    {Neutral,100}
    }, 3};

static const Animation Animations[1] = { 
    AniAngry
};

#endif // BenderAnimations_h
