//
// Created by mabartos on 4/19/21.
//

#include "default/DefaultOnlineIRCap.h"

DefaultOnlineIRCap::DefaultOnlineIRCap(shared_ptr <PubSubDataConnector> dataConnector,
                                       const uint8_t &pin,
                                       const string &name) :
        DefaultIRCap(pin, name),
        InfraRedData(dataConnector) {
}

void DefaultOnlineIRCap::execute() {
    DefaultIRCap::execute();
    sendData();
}
