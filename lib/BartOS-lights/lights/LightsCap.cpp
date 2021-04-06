#include "LightsCap.h"

LightsCap::LightsCap(const uint8_t &pin, const string &name, uint32_t pwmRange) :
        Capability(pin, name, CapabilityType::LIGHT),
        _pwm_range(pwmRange) {
}

uint32_t LightsCap::getPwmRange() {
    return _pwm_range;
}

void LightsCap::setPwmRange(uint32_t range) {
    _pwm_range = range;
}