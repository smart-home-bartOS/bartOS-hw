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
    digitalWrite(_pin, LOW);
}

void DefaultLightsCap::turnOn() {
    digitalWrite(_pin, HIGH);
}

void DefaultLightsCap::turnOff() {
    digitalWrite(_pin, HIGH);
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
