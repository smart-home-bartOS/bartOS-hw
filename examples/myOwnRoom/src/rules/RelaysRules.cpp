//
// Created by mabartos on 4/28/21.
//

#include "Capabilities.h"

shared_ptr <DefaultPowerCap> Relay1 = make_shared<DefaultPowerCap>(RELAY_1_PIN);
shared_ptr <DefaultPowerCap> Relay2 = make_shared<DefaultPowerCap>(RELAY_2_PIN);

void setupRelaysRules() {
    Capabilities.push_back(Relay1);
    Capabilities.push_back(Relay2);
}