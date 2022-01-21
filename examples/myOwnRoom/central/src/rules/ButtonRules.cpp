//
// Created by mabartos on 4/28/21.
//

#include "Capabilities.h"

shared_ptr <TwoWayButton> LeftMainButton = make_shared<TwoWayButton>(LEFT_MAIN_BTN_PIN);
shared_ptr <TwoWayButton> RightMainButton = make_shared<TwoWayButton>(RIGHT_MAIN_BTN_PIN);

void setupLeftButton() {
    LeftMainButton->onChange([]() {
        UnderLights->switchState();
        RgbRelay->switchState();
    });
}

void setupRightButton() {
    RightMainButton->onChange([]() {
        MainLights->switchState();
    });
}

void setupButtonsRules() {
    setupLeftButton();
    setupRightButton();

    Capabilities.push_back(LeftMainButton);
    Capabilities.push_back(RightMainButton);
}