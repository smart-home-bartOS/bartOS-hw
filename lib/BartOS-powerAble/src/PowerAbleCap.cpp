//
// Created by mabartos on 4/12/21.
//

#include "PowerAbleCap.h"

PowerAbleCap::PowerAbleCap(const uint8_t &pin,
                           const string &type,
                           const string &name) : Capability(pin, type, name) {}

bool PowerAbleCap::isTurnedOn() {
    return _isTurnedOn;
}

void PowerAbleCap::setTurnedOn(bool state) {
    _isTurnedOn = state;
}

void PowerAbleCap::turnOn() {
    _isTurnedOn = true;
}

void PowerAbleCap::turnOff() {
    _isTurnedOn = false;
}

void PowerAbleCap::changeState(bool state) {
    state ? turnOn() : turnOff();
    setTurnedOn(state);
}

void PowerAbleCap::switchState() {
    bool state = _isTurnedOn;
    state ? turnOff() : turnOn();
    _isTurnedOn = !state;
}

bool PowerAbleCap::isInverseOutput() {
    return _isInverseOutput;
}

void PowerAbleCap::setInverseOutput(bool state) {
    _isInverseOutput = state;
}