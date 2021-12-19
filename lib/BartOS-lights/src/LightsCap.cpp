#include "LightsCap.h"

#include <Arduino.h>

LightsCap::LightsCap(const uint8_t &pin,
                     const string &name,
                     uint32_t pwmRange) : PowerAbleCap(pin, CapabilityType::LIGHT, name),
                                          _pwmRange(pwmRange) {
}

uint8_t LightsCap::getActualIntensity() {
    return _intensity;
}

void LightsCap::turnOn() {
    PowerAbleCap::turnOn();
    _intensity = 100;
}

void LightsCap::turnOff() {
    PowerAbleCap::turnOff();
    _intensity = 0;
}

bool LightsCap::isTurnedOn() {
    return getActualIntensity() > 0 && PowerAbleCap::isTurnedOn();
}

void LightsCap::increaseIntensity() {
    if (getActualIntensity() == 0) {
        changeIntensity(25);
    } else if (getActualIntensity() <= 25) {
        changeIntensity(50);
    } else if (getActualIntensity() <= 50) {
        changeIntensity(75);
    } else if (getActualIntensity() <= 75) {
        turnOn();
    }
}

void LightsCap::decreaseIntensity() {
    if (getActualIntensity() >= 90) {
        changeIntensity(75);
    } else if (getActualIntensity() >= 75) {
        changeIntensity(50);
    } else if (getActualIntensity() >= 50) {
        changeIntensity(25);
    } else {
        turnOff();
    }
}

uint32_t LightsCap::getPwmRange() {
    return _pwmRange;
}

void LightsCap::setPwmRange(uint32_t range) {
    _pwmRange = range;
}

bool LightsCap::validIntensity(uint8_t intensity) {
    return intensity >= 0 && intensity <= 100;
}