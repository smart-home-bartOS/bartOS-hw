//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_LIGHTSDATA_H
#define BARTOS_HW_LIGHTSDATA_H

#include <LightsCap.h>
#include <capability/OnlineCapability.h>

class LightsOnline : public OnlineCapability<LightsCap> {
   public:
    static const char *INTENSITY;
    static const char *STATE;

    LightsOnline(LightsCap *capability);

    ~LightsOnline() = default;

    DynamicJsonDocument getData() override;
    void handleData(DynamicJsonDocument &data) override;
};

#endif  // BARTOS_HW_LIGHTSDATA_H
