/*******************************************************************
    Button.cpp
    Brett Martin
    7/1/2020
    
    Simple class to handle button input with debounce support
********************************************************************/

#include "Button.h"

Button::Button(byte pin) {
    _pin = pin;
    _lastState = LOW;
    init();
}
    
void Button::init() {
    pinMode(_pin, INPUT_PULLDOWN); // INPUT_PULLDOWN used for boards with built in pulldown resistors
    update();
}
    
void Button::update() {
    byte currentState = digitalRead(_pin);
      
    if (currentState != _lastState) {
        _lastDebounceTime = millis();
    }
    
    if ( millis() - _lastDebounceTime > _debounceDelay ) {
        _state = currentState;
    }
    
    _lastState = currentState;
}
    
byte Button::getState() {
    update();
    return _state;
}

bool Button::isPressed() {
    if (getState() == HIGH) {
        Serial.println("Button Pushed");
        return true;
    }
    return false;
}

bool Button::wasPressed() {
    byte currentState = getState();
    if (currentState == HIGH && _pressedOnce == false) {
        // Serial.println("Button Pushed once");
        _pressedOnce = true;
        return true;
    } else if (currentState == LOW && _pressedOnce == true) {
        _pressedOnce = false;
        // Serial.println("Button Reset");
    }

    return false;
}
