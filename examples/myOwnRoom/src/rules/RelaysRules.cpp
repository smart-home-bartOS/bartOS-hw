//
// Created by mabartos on 4/28/21.
//

#include "Capabilities.h"

shared_ptr <DefaultPowerCap> RgbRelay = make_shared<DefaultPowerCap>(RGB_RELAY_PIN);
shared_ptr <DefaultPowerCap> Relay2 = make_shared<DefaultPowerCap>(RELAY_2_PIN);

void setupRelaysRules() {
    RgbRelay->turnOff();
    Relay2->turnOff();

    Capabilities.push_back(RgbRelay);
    Capabilities.push_back(Relay2);
}