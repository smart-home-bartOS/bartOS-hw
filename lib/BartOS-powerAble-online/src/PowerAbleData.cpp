//
// Created by mabartos on 4/19/21.
//

#include "PowerAbleData.h"

const char *PowerAbleData::STATE = "state";
const char *PowerAbleData::SWITCH = "switch";

PowerAbleData::PowerAbleData(shared_ptr<PubSubDataConnector> dataConnector) :
        PubSubDataTransceiver(dataConnector) {
}

void PowerAbleData::sendData(PowerAbleCap *cap) {
    if (cap == nullptr)return;

    DynamicJsonDocument data(100);
    data[STATE] = cap->isTurnedOn();

    data.shrinkToFit();
    sendDataToDefault(data);
    data.garbageCollect();
}

void PowerAbleData::initDataHandler(PowerAbleCap *cap, long deviceID, long homeID, long roomID) {
    if (cap == nullptr) return;

    auto setValues = [cap](JsonObject &obj) -> void {
        if (containKey(obj, STATE)) {
            const bool state = obj[STATE];
            cap->changeState(state);
        } else if (containKey(obj, SWITCH)) {
            const bool switchState = obj[SWITCH];
            cap->switchState();
        }
    };

    addSameCallbackForBasicTopics(cap, setValues, deviceID, homeID, roomID);
}