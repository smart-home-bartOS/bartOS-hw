//
// Created by mabartos on 4/11/21.
//

#include "TwoWayButton.h"
#include <Arduino.h>

TwoWayButton::TwoWayButton(const uint8_t &pin, const string &name) : ButtonCap(pin, name) {}

void TwoWayButton::updateState() {
    _state = digitalRead(_pin);
}

void TwoWayButton::init() {
    pinMode(_pin, INPUT_PULLUP);
}

void TwoWayButton::execute() {
    updateState();
}

bool TwoWayButton::isOn() {
    updateState();
    return _state;
}

bool TwoWayButton::isOff() {
    updateState();
    return !_state;
}

bool TwoWayButton::isChanged() {
    return _state != digitalRead(_pin);
}