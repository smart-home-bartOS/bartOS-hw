//
// Created by mabartos on 4/19/21.
//

#include "default/DhtHumOnline.h"

DhtHumOnline::DhtHumOnline(shared_ptr<PubSubDataConnector> dataConnector,
                           const uint8_t &pin,
                           const uint8_t &dhtType,
                           const string &name) :
        DhtHumSensor(pin, dhtType, name),
        HumidityData(dataConnector) {
}

void DhtHumOnline::execute() {
    DhtHumSensor::execute();
    sendData();
}