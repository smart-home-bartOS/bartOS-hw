//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_BUTTON_ONLINE_H
#define BARTOS_HW_BUTTON_ONLINE_H

#include <ButtonCap.h>

#include "capability/OnlineCapability.h"

class ButtonOnline : public OnlineCapability<ButtonCap> {
   public:
    static const char *STATE;

    ButtonOnline(ButtonCap *capability);

    ~ButtonOnline() = default;

    DynamicJsonDocument getData() override;
    vector<string> getSubscribedPaths() override;
};

#endif  // BARTOS_HW_BUTTON_ONLINE_H
