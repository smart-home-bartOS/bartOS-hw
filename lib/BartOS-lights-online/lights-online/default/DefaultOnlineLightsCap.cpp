//
// Created by mabartos on 4/19/21.
//

#include "DefaultOnlineLightsCap.h"

DefaultOnlineLightsCap::DefaultOnlineLightsCap(shared_ptr<PubSubDataConnector> dataConnector,
                                               const uint8_t &pin,
                                               const string &name,
                                               uint32_t pwmRange) :
        DefaultLightsCap(pin, name, pwmRange),
        LightsData(dataConnector) {
}

void DefaultOnlineLightsCap::execute() {
    DefaultLightsCap::execute();
    sendData();
}