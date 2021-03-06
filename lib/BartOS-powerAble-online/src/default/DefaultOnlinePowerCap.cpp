//
// Created by mabartos on 4/19/21.
//

#include "default/DefaultOnlinePowerCap.h"

DefaultOnlinePowerCap::DefaultOnlinePowerCap(shared_ptr <PubSubDataConnector> dataConnector,
                                             const uint8_t &pin,
                                             const string &name) :
        DefaultPowerCap(pin, name),
        PowerAbleData(dataConnector) {
}

void DefaultOnlinePowerCap::init() {
    DefaultPowerCap::init();
    PowerAbleData::initDataHandler(this);
}

void DefaultOnlinePowerCap::execute() {
    DefaultPowerCap::execute();
    sendData();
}
