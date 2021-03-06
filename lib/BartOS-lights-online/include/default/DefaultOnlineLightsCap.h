//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_DEFAULTONLINELIGHTSCAP_H
#define BARTOS_HW_DEFAULTONLINELIGHTSCAP_H

#include <default/DefaultLightsCap.h>
#include "LightsData.h"

class DefaultOnlineLightsCap : public DefaultLightsCap, public LightsData {
public:
    DefaultOnlineLightsCap(shared_ptr<PubSubDataConnector> dataConnector,
                           const uint8_t &pin,
                           const string &name = "Default-online-lights-cap",
                           uint32_t pwmRange = DEFAULT_PWM_RANGE
    );

    ~DefaultOnlineLightsCap() = default;

    void init() override;

    void execute() override;

    void sendData();
};


#endif //BARTOS_HW_DEFAULTONLINELIGHTSCAP_H
