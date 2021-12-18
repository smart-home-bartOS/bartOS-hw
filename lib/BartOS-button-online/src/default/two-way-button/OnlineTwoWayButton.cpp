//
// Created by mabartos on 4/19/21.
//

#include "default/two-way-button/OnlineTwoWayButton.h"

OnlineTwoWayButton::OnlineTwoWayButton(const uint8_t &pin,
                                       const string &name) : TwoWayButton(pin, name),
                                                             ButtonOnline(this) {
}

void OnlineTwoWayButton::loop() {
    TwoWayButton::loop();
}