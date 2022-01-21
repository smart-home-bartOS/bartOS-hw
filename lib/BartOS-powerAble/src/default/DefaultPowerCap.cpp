//
// Created by mabartos on 4/13/21.
//

#include "default/DefaultPowerCap.h"

#include <Arduino.h>

DefaultPowerCap::DefaultPowerCap(const uint8_t &pin) : PowerAbleCap(pin, CapabilityType::RELAY) {}

void DefaultPowerCap::init() {
    pinMode(_pin, OUTPUT);
}

void DefaultPowerCap::turnOn() {
    digitalWrite(_pin, isInverseOutput() ? HIGH : LOW);
    setTurnedOn(true);
}

void DefaultPowerCap::turnOff() {
    digitalWrite(_pin, isInverseOutput() ? LOW : HIGH);
    setTurnedOn(false);
}