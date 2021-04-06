#include "TemperatureCap.h"
#include <core/capability/CapabilityType.h>

TemperatureCap::TemperatureCap(const uint8_t &pin, const string &name, unsigned sampleTime) :
        Capability(pin, CapabilityType::TEMPERATURE, name, sampleTime) {
}

float TemperatureCap::getTemperature() {
    return _temp;
}

void TemperatureCap::setTemperature(const float &temp) {
    _temp = temp;
}

string TemperatureCap::getUnits() {
    return _units;
}

void TemperatureCap::setUnits(const string &units) {
    _units = units;
}