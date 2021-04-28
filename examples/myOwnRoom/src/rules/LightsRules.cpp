//
// Created by mabartos on 4/28/21.
//

#include "Capabilities.h"

shared_ptr <DefaultLightsCap> MainLights = make_shared<DefaultLightsCap>(MAIN_LIGHTS_PIN, "MainLights");
shared_ptr <DefaultLightsCap> UnderLights = make_shared<DefaultLightsCap>(UNDER_LIGHTS_PIN, "UnderLights");

void setupLightsRules() {
    Capabilities.push_back(MainLights);
    Capabilities.push_back(UnderLights);
}

