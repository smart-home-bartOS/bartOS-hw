#include "TemperatureCap.h"

#include <capability/CapabilityType.h>

TemperatureCap::TemperatureCap(const uint8_t &pin, unsigned sampleTime) : Capability(pin, CapabilityType::TEMPERATURE, sampleTime) {
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