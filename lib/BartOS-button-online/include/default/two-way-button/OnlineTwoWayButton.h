//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_ONLINETWOWAYBUTTON_H
#define BARTOS_HW_ONLINETWOWAYBUTTON_H

#include <capability/OnlineCapability.h>
#include <default/two-way-button/TwoWayButton.h>

#include "ButtonOnline.h"

class OnlineTwoWayButton : public TwoWayButton, public ButtonOnline {
   public:
    OnlineTwoWayButton(const uint8_t &pin,
                       const string &name = "Online-2W-button");

    ~OnlineTwoWayButton() = default;

    void loop() override;
};

#endif  // BARTOS_HW_ONLINETWOWAYBUTTON_H
