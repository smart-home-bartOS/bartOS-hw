//
// Created by mabartos on 4/28/21.
//

#include "Capabilities.h"

shared_ptr <DefaultLightsCap> MainLights = make_shared<DefaultLightsCap>(MAIN_LIGHTS_PIN);
shared_ptr <DefaultLightsCap> UnderLights = make_shared<DefaultLightsCap>(UNDER_LIGHTS_PIN);

void setupLightsRules() {
    UnderLights->smoothMode(true);
    MainLights->smoothMode(true);

    Capabilities.push_back(MainLights);
    Capabilities.push_back(UnderLights);
}

