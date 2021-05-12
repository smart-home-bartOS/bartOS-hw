//
// Created by mabartos on 3/20/21.
//

#include "default/DhtTempSensor.h"

const char *DhtTempSensor::DEFAULT_NAME = "DHT_TEMP";

DhtTempSensor::DhtTempSensor(const uint8_t &pin,
                             const uint8_t &dhtType,
                             const string &name) :
        TemperatureCap(pin, name), _dhtType(dhtType) {
}

bool DhtTempSensor::isValidDHT() {
    return _dht != nullptr;
}

void DhtTempSensor::init() {
    if (!isValidDHT()) return;

    _dht->begin();
}

void DhtTempSensor::execute() {
    if (!isValidDHT()) return;

    float temp = _dht->readTemperature();

    if (!isnan(temp)) {
        setTemperature(temp);
    }
}

uint8_t DhtTempSensor::getDhtType() {
    return _dhtType;
}