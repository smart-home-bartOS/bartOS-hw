//
// Created by mabartos on 4/19/21.
//

#include "default/DhtHumSensor.h"

DhtHumSensor::DhtHumSensor(const uint8_t &pin,
                           const uint8_t &dhtType) : HumidityCap(pin), _dhtType(dhtType) {
}

bool DhtHumSensor::isValidDHT() {
    return _dht != nullptr;
}

void DhtHumSensor::init() {
    if (!isValidDHT()) return;

    _dht->begin();
}

void DhtHumSensor::loop() {
    if (!isValidDHT()) return;

    float humidity = _dht->readHumidity();

    if (!isnan(humidity)) {
        setHumidity(humidity);
    }
}

uint8_t DhtHumSensor::getDhtType() {
    return _dhtType;
}