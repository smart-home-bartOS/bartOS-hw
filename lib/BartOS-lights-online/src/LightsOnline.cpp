//
// Created by mabartos on 4/19/21.
//

#include "LightsOnline.h"

const char *LightsOnline::INTENSITY = "intensity";
const char *LightsOnline::STATE = "state";

LightsOnline::LightsOnline(LightsCap *capability) : OnlineCapability<LightsCap>(capability) {
}

DynamicJsonDocument LightsOnline::getData() {
    DynamicJsonDocument data(100);
    data[INTENSITY] = getTargetCapability()->getActualIntensity();
    data[STATE] = getTargetCapability()->isTurnedOn();

    data.shrinkToFit();
    data.garbageCollect();
    return data;
}

void LightsOnline::handleData(DynamicJsonDocument &data) {
    OnlineCapability::handleData(data);

    JsonObject obj = data.as<JsonObject>();
    if (containKey(obj, STATE)) {
        const bool state = obj[STATE];
        getTargetCapability()->changeState(state);
    }

    if (containKey(obj, INTENSITY)) {
        const uint8_t intensity = obj[INTENSITY];
        getTargetCapability()->changeIntensity(intensity);
    }
}