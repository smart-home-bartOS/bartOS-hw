//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_ONLINETWOWAYBUTTON_H
#define BARTOS_HW_ONLINETWOWAYBUTTON_H

#include <default/two-way-button/TwoWayButton.h>
#include "ButtonData.h"

class OnlineTwoWayButton : public TwoWayButton, public ButtonData {
public:
    OnlineTwoWayButton(shared_ptr <PubSubDataConnector> dataConnector,
                       const uint8_t &pin,
                       const string &name = "Online-2W-button");

    ~OnlineTwoWayButton() = default;

    void execute();

    void sendData() {
        ButtonData::sendData(this);
    }
};


#endif //BARTOS_HW_ONLINETWOWAYBUTTON_H
