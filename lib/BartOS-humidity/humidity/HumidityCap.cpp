#include "HumidityCap.h"

HumidityCap::HumidityCap(const uint8_t &pin, const string &name, unsigned sampleTime) :
        Capability(pin, CapabilityType::HUMIDITY, name, sampleTime) {}
        
uint8_t HumidityCap::getHumidity() {
    return _humidity;
}

void HumidityCap::setHumidity(const uint8_t &hum) {
    _humidity = hum;
}