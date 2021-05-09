//
// Created by mabartos on 4/19/21.
//

#include "default/DefaultOnlineLightsCap.h"

DefaultOnlineLightsCap::DefaultOnlineLightsCap(shared_ptr<PubSubDataConnector> dataConnector,
                                               const uint8_t &pin,
                                               const string &name,
                                               uint32_t pwmRange) :
        DefaultLightsCap(pin, name, pwmRange),
        LightsData(dataConnector) {
}

void DefaultOnlineLightsCap::init() {
    DefaultLightsCap::init();
    LightsData::initDataHandler(this);
}

void DefaultOnlineLightsCap::execute() {
    DefaultLightsCap::execute();
    sendData();
}

void DefaultOnlineLightsCap::sendData() {
    LightsData::sendData(this);
}