/*******************************************************************
    Bender.cpp
    Brett Martin
    7/1/2020
    
    Wrapping class for all Bender functions and classes into a single
    Bender class.
********************************************************************/

#include "Bender.h"


Bender::Bender() {
    init();
}

void Bender::init() {
    _antenna = new Led(13);
    _buttonRed = new Button(19); 
    _buttonYellow = new Button(18); 
    _buttonGreen = new Button(17); 
    _buttonBlue = new Button(16); 
    _buttonWhite = new Button(15); 
    _clock = new BenderTime();
    _display = new BenderDisplay(4,1); //# segments, brightness etc pass in
    _mouth = new BenderSound();
}

bool Bender::buttonPushed(int b) {
    switch (b)
    {
    case 1:
        return _buttonRed->wasPressed();
        break;
    case 2:
        return _buttonYellow->wasPressed();
        break;
    case 3:
        return _buttonGreen->wasPressed();
        break;
    case 4:
        return _buttonBlue->wasPressed();
        break;
    case 5:
        return _buttonWhite->wasPressed();
        break;
    
    default:
        break;
    }
    return false;
}

void Bender::antennaOn(byte state) {
    if (state)
         _antenna->on(1000);
    else
         _antenna->off();
}

void Bender::showClock() {
    int time = _clock->getTime();

    _display->clear();

    // Convert clock int eg (1234) to single digits 1,2,3,4
    unsigned m2 = (time / 1U) % 10;
    unsigned m1 = (time / 10U) % 10;
    unsigned h2 = (time / 100U) % 10;
    unsigned h1 = (time / 1000U) % 10;

    // Serial.printf("time: %d%d:%d%d \n", h1, h2, m1, m2);
  
    if (h1 == 0) {
        _display->showNumber(10,0);
    }
    else {
        _display->showNumber(h1,0);
    }
    _display->showNumber(h2,1);
    _display->showNumber(m1,2);
    _display->showNumber(m2,3);

    _display->writeDisplay();
}

void Bender::blinkColon () {
    _display->blinkColon();
}

void Bender::showExpression(ExpressionNames expression) {
    _display->showExpression(expression);
}

void Bender::playAnimation(AnimationNames animation) {
    _mouth->playSound(Animations[animation].audio);
    for (AnimationFrame frame: Animations[animation].frames) {
        _display->showExpression(frame.exp);
        delay(frame.waitTime);
    }
}

void Bender::say(int sound) {
    _mouth->playSound(sound);
}

void Bender::displayOn(bool state) {
    _display->clear();
    _display->colonOn(false);
}

int Bender::getTime() {
    return _clock->getTime();
}
