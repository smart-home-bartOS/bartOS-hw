#include "HumidityCap.h"

HumidityCap::HumidityCap(const uint8_t &pin) : Capability(pin) {
}

HumidityCap::HumidityCap(const uint8_t &pin, const string &name) :
        Capability(pin, CapabilityType::HUMIDITY, name) {}

HumidityCap::HumidityCap(const uint8_t &pin, unsigned sampleTime) :
        Capability(pin, CapabilityType::HUMIDITY, sampleTime) {
}

HumidityCap::HumidityCap(const uint8_t &pin, const string &name, unsigned sampleTime) :
        Capability(pin, CapabilityType::HUMIDITY, name, sampleTime) {}


uint8_t HumidityCap::getHumidity() {
    return _humidity;
}

void HumidityCap::setHumidity(const uint8_t &hum) {
    _humidity = hum;
}