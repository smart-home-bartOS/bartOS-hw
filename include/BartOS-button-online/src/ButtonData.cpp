//
// Created by mabartos on 4/19/21.
//

#include "ButtonData.h"

const char *ButtonData::STATE = "state";

ButtonData::ButtonData(shared_ptr<PubSubDataConnector> dataConnector) :
        PubSubDataTransceiver(dataConnector) {
}

void ButtonData::sendData(ButtonCap *cap) {
    if (cap == nullptr) return;

    DynamicJsonDocument data(100);
    data[STATE] = cap->isOn();

    data.shrinkToFit();
    sendDataToDefault(data);
    data.garbageCollect();
}