//
// Created by mabartos on 4/19/21.
//

#include "InfraRedData.h"

const char *InfraRedData::VALUE;

InfraRedData::InfraRedData(shared_ptr<PubSubDataConnector> dataConnector) :
        PubSubDataTransceiver(dataConnector) {
}

void InfraRedData::sendData(InfraRedCap *cap) {
    if (cap == nullptr) return;

    DynamicJsonDocument data(100);
    data[VALUE] = cap->getSignalValue();

    data.shrinkToFit();
    sendDataToDefault(data);
    data.garbageCollect();
}