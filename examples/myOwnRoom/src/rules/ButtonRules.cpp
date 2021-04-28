//
// Created by mabartos on 4/28/21.
//

#include "Capabilities.h"

shared_ptr <TwoWayButton> LeftMainButton = make_shared<TwoWayButton>(LEFT_MAIN_BTN_PIN, "LeftMainButton");
shared_ptr <TwoWayButton> RightMainButton = make_shared<TwoWayButton>(RIGHT_MAIN_BTN_PIN, "RightMainButton");

void setupLeftButton() {
    LeftMainButton->executeEventHandler()->add("Check Left Button", []() {
        if (LeftMainButton->isChanged()) {
            MainLights->switchState();
        }
    });
}

void setupRightButton() {
    RightMainButton->executeEventHandler()->add("Check Right Button", []() {
        if (RightMainButton->isChanged()) {
            UnderLights->switchState();
        }
    });
}

void setupButtonsRules() {
    setupLeftButton();
    setupRightButton();

    Capabilities.push_back(LeftMainButton);
    Capabilities.push_back(RightMainButton);
}