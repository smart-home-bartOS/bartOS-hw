//
// Created by mabartos on 4/19/21.
//

#include "default/two-way-button/OnlineTwoWayButton.h"

OnlineTwoWayButton::OnlineTwoWayButton(const uint8_t &pin,
                                       const string &name) : TwoWayButton(pin, name),
                                                             OnlineCapability(pin, name) {
}

void OnlineTwoWayButton::loop() {
    TwoWayButton::loop();
    sendData();
}

DynamicJsonDocument OnlineTwoWayButton::getData() {
}
void OnlineTwoWayButton::handleData(const DynamicJsonDocument &data) {
}
vector<string> OnlineTwoWayButton::getSubscribedPaths() {
}