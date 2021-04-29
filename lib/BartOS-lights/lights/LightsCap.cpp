#include "LightsCap.h"

LightsCap::LightsCap(const uint8_t &pin, const string &name, uint32_t pwmRange) :
        PowerAbleCap(pin, CapabilityType::LIGHT, name),
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

void LightsCap::increaseIntensity() {
    if (_intensity <= 25) {
        changeIntensity(50);
    } else if (_intensity <= 50) {
        changeIntensity(75);
    } else if (_intensity <= 75) {
        changeIntensity(100);
    }
}

void LightsCap::decreaseIntensity() {
    if (_intensity >= 90) {
        changeIntensity(75);
    } else if (_intensity >= 75) {
        changeIntensity(50);
    } else if (_intensity >= 50) {
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