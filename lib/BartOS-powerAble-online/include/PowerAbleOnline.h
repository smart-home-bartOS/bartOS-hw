//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_POWERABLEDATA_H
#define BARTOS_HW_POWERABLEDATA_H

#include <PowerAbleCap.h>
#include <capability/OnlineCapability.h>

class PowerAbleOnline : public OnlineCapability<PowerAbleCap> {
   public:
    static const char *STATE;
    static const char *SWITCH;

    PowerAbleOnline(PowerAbleCap *capability);

    ~PowerAbleOnline() = default;

    DynamicJsonDocument getData() override;
    void handleData(DynamicJsonDocument &data) override;
    vector<string> getSubscribedPaths() override;
};

#endif  // BARTOS_HW_POWERABLEDATA_H
