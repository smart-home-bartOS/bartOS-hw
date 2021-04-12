#include "LightsCap.h"

LightsCap::LightsCap(const uint8_t &pin, const string &name, uint32_t pwmRange) :
        PowerAbleCap(pin, CapabilityType::LIGHT, name),
        _pwmRange(pwmRange) {
}

uint32_t LightsCap::getPwmRange() {
    return _pwmRange;
}

void LightsCap::setPwmRange(uint32_t range) {
    _pwmRange = range;
}