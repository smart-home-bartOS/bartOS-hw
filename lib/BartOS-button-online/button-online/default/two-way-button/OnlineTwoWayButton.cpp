//
// Created by mabartos on 4/19/21.
//

#include "OnlineTwoWayButton.h"

OnlineTwoWayButton::OnlineTwoWayButton(shared_ptr <PubSubDataConnector> dataConnector,
                                       const uint8_t &pin,
                                       const string &name) :
        TwoWayButton(pin, name),
        ButtonData(dataConnector) {
}

void OnlineTwoWayButton::execute() {
    TwoWayButton::execute();
    sendData();
}