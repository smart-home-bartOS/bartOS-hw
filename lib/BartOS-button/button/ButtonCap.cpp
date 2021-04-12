//
// Created by mabartos on 4/11/21.
//

#include "ButtonCap.h"

ButtonCap::ButtonCap(const uint8_t &pin, const string &name) :
        Capability(pin, CapabilityType::BUTTON, name, DEFAULT_DELAY_MILLIS) {
}

bool ButtonCap::isOn() {
    return _state;
}

bool ButtonCap::isOff() {
    return !_state;
}