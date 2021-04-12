//
// Created by mabartos on 4/19/21.
//

#include "DefaultOnlinePowerCap.h"

DefaultOnlinePowerCap::DefaultOnlinePowerCap(shared_ptr <PubSubDataConnector> dataConnector,
                                             const uint8_t &pin,
                                             const string &name) :
        DefaultPowerCap(pin, name),
        PowerAbleData(dataConnector) {
}

void DefaultOnlinePowerCap::execute() {
    DefaultPowerCap::execute();
    sendData();
}
