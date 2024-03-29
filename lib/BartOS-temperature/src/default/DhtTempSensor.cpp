//
// Created by mabartos on 3/20/21.
//

#include "default/DhtTempSensor.h"

DhtTempSensor::DhtTempSensor(const uint8_t &pin,
                             const uint8_t &dhtType) : TemperatureCap(pin), _dhtType(dhtType) {
}

bool DhtTempSensor::isValidDHT() {
    return _dht != nullptr;
}

void DhtTempSensor::init() {
    if (!isValidDHT()) return;

    _dht->begin();
}

void DhtTempSensor::loop() {
    if (!isValidDHT()) return;

    float temp = _dht->readTemperature();

    if (!isnan(temp)) {
        setTemperature(temp);
    }
}

uint8_t DhtTempSensor::getDhtType() {
    return _dhtType;
}