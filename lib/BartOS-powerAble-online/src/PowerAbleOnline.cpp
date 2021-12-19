//
// Created by mabartos on 4/19/21.
//

#include "PowerAbleOnline.h"

const char *PowerAbleOnline::STATE = "state";
const char *PowerAbleOnline::SWITCH = "switch";

PowerAbleOnline::PowerAbleOnline(PowerAbleCap *capability) : OnlineCapability(capability) {
}

DynamicJsonDocument PowerAbleOnline::getData() {
    DynamicJsonDocument data(50);
    data[STATE] = getTargetCapability()->isTurnedOn();

    data.shrinkToFit();
    data.garbageCollect();
    return data;
}

void PowerAbleOnline::handleData(DynamicJsonDocument &data) {
    OnlineCapability::handleData(data);
    JsonObject obj = data.as<JsonObject>();

    if (containsKey(obj, STATE)) {
        const bool state = obj[STATE];
        getTargetCapability()->changeState(state);
    } else if (containsKey(obj, SWITCH)) {
        const bool switchState = obj[SWITCH];
        getTargetCapability()->switchState();
    }
}

vector<string> PowerAbleOnline::getSubscribedPaths() {
    vector<string> vec;
    vec.push_back("/cap/power-able/" + getID());
    return vec;
}