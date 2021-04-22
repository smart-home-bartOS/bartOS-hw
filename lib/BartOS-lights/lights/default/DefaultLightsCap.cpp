//
// Created by mabartos on 4/6/21.
//

#include "DefaultLightsCap.h"
#include <Arduino.h>

DefaultLightsCap::DefaultLightsCap(const uint8_t &pin, const string &name, uint32_t pwmRange) :
        LightsCap(pin, name, pwmRange) {
}

void DefaultLightsCap::init() {
    pinMode(_pin, OUTPUT);
    turnOff();
}

void DefaultLightsCap::turnOn() {
    LightsCap::turnOn();
    digitalWrite(_pin, isInverseOutput() ? LOW : HIGH);
}

void DefaultLightsCap::turnOff() {
    LightsCap::turnOff();
    digitalWrite(_pin, isInverseOutput() ? HIGH : LOW);
}

void DefaultLightsCap::changeIntensity(uint8_t intensity) {
    if (intensity >= 100) {
        _intensity = 100;
        turnOn();
        return;
    } else if (intensity == 0) {
        turnOff();
        return;
    }

    float resultIntensity = (getPwmRange() / 100.0) * intensity;
    analogWrite(_pin, (uint16_t) resultIntensity);
    _intensity = intensity;
}
