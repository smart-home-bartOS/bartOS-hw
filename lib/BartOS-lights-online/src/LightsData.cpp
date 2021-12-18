//
// Created by mabartos on 4/19/21.
//

#include "LightsData.h"
#include <utils/PubSubTopics.h>

const char *LightsData::INTENSITY = "intensity";
const char *LightsData::STATE = "state";

LightsData::LightsData(shared_ptr <PubSubDataConnector> dataConnector) :
        PubSubDataTransceiver(dataConnector) {
}

void LightsData::sendData(LightsCap *cap) {
    if (cap == nullptr) return;

    DynamicJsonDocument data(100);
    data[INTENSITY] = cap->getActualIntensity();
    data[STATE] = cap->isTurnedOn();

    data.shrinkToFit();
    sendDataToDefault(data);
    data.garbageCollect();
}

void LightsData::initDataHandler(LightsCap *cap, long deviceID, long homeID, long roomID) {
    if (cap == nullptr) return;

    auto setValues = [cap](JsonObject &doc) -> void {
        if (containKey(doc, STATE)) {
            const bool state = doc[STATE];
            cap->changeState(state);

            if (state && containKey(doc, INTENSITY)) {
                const uint8_t intensity = doc[INTENSITY];
                cap->changeIntensity(intensity);
            }
        }
    };

    addSameCallbackForBasicTopics(cap, setValues, deviceID, homeID, roomID);
}