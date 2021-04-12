//
// Created by mabartos on 4/12/21.
//

#include "PowerAbleCap.h"

PowerAbleCap::PowerAbleCap(const uint8_t &pin,
                           const string &type,
                           const string &name) :
        Capability(pin, type, name) {}

bool PowerAbleCap::isTurnedOn() {
    return _isTurnedOn;
}

void PowerAbleCap::changeState(bool state) {
    state ? turnOn() : turnOff();
    _isTurnedOn = state;
}

void PowerAbleCap::switchState() {
    _isTurnedOn ? turnOff() : turnOn();
    _isTurnedOn = !_isTurnedOn;
}