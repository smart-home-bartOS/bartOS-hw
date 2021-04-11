#include "LightsCap.h"

LightsCap::LightsCap(const uint8_t &pin, const string &name, uint32_t pwmRange) :
        Capability(pin, name, CapabilityType::LIGHT),
        _pwmRange(pwmRange) {
}

uint32_t LightsCap::getPwmRange() {
    return _pwmRange;
}

void LightsCap::setPwmRange(uint32_t range) {
    _pwmRange = range;
}

bool LightsCap::isTurnedOn() {
    return _isTurnedOn;
}

void LightsCap::setIsTurnedOn(bool state) {
    _isTurnedOn = state;
}

void LightsCap::turnOn() {
    setIsTurnedOn(true);
}

void LightsCap::turnOff() {
    setIsTurnedOn(false);
}

void LightsCap::switchState() {
    isTurnedOn() ? turnOff() : turnOn();
}