#include "TemperatureCap.h"
#include <core/capability/CapabilityType.h>

TemperatureCap::TemperatureCap(const uint8_t &pin) : Capability(pin) {
    setType(CapabilityType::TEMPERATURE);
    setSampleTime(DEFAULT_SAMPLE_TIME_MS);
}

TemperatureCap::TemperatureCap(const uint8_t &pin, const string &name) :
        TemperatureCap(pin) {
    setName(name);
}

TemperatureCap::TemperatureCap(const uint8_t &pin, unsigned sampleTime) :
        TemperatureCap(pin) {
    setSampleTime(sampleTime);
}

TemperatureCap::TemperatureCap(const uint8_t &pin, const string &name, unsigned sampleTime) :
        TemperatureCap(pin, name) {
    setSampleTime(sampleTime);
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