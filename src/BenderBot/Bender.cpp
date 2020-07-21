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
    _display = new BenderDisplay(4,5); //# segments, brightness etc pass in
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
    struct TimeArray t = _clock->getTimeArray();
    Serial.printf("Time is %d%d:%d%d",t.h1,t.h2,t.m1,t.m2);

    _display->clear();
    if (t.h1 == 0) {
        _display->showNumber(10,0);
    }
    else {
        _display->showNumber(t.h1,0);
    }
    _display->showNumber(t.h2,1);
    _display->showNumber(t.m1,2);
    _display->showNumber(t.m2,3);

    _display->writeDisplay();
    _display->colonOn(true);
}

void Bender::showExpression(ExpressionNames expression) {
    _display->showExpression(expression);
}

void Bender::playAnimation(String animation) {
    _display->clear();
    _display->showExpression(Angry);
    _mouth->playSound(8);
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
