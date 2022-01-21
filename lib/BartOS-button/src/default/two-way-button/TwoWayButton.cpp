//
// Created by mabartos on 4/11/21.
//

#include "default/two-way-button/TwoWayButton.h"

#include <Arduino.h>

TwoWayButton::TwoWayButton(const uint8_t &pin) : ButtonCap(pin) {}

void TwoWayButton::updateState() {
    _state = digitalRead(_pin);
}

void TwoWayButton::init() {
    pinMode(_pin, INPUT_PULLUP);
    ButtonCap::init();
}

bool TwoWayButton::isOn() {
    updateState();
    return _state;
}

bool TwoWayButton::isOff() {
    updateState();
    return !_state;
}