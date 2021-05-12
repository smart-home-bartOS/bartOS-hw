//
// Created by mabartos on 4/19/21.
//

#include "default/DhtHumSensor.h"

DhtHumSensor::DhtHumSensor(const uint8_t &pin,
                           const uint8_t &dhtType,
                           const string &name) :
        HumidityCap(pin, name), _dhtType(dhtType) {
}

bool DhtHumSensor::isValidDHT() {
    return _dht != nullptr;
}

void DhtHumSensor::init() {
    if (!isValidDHT()) return;

    _dht->begin();
}

void DhtHumSensor::execute() {
    if (!isValidDHT()) return;

    float humidity = _dht->readHumidity();

    if (!isnan(humidity)) {
        setHumidity(humidity);
    }
}

uint8_t DhtHumSensor::getDhtType() {
    return _dhtType;
}

const char *DhtHumSensor::DEFAULT_NAME = "DHT_HUM";
