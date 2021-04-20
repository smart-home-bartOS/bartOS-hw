//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_DEFAULTONLINELIGHTSCAP_H
#define BARTOS_HW_DEFAULTONLINELIGHTSCAP_H

#include <lights/default/DefaultLightsCap.h>
#include <lights-online/LightsData.h>

class DefaultOnlineLightsCap : public DefaultLightsCap, public LightsData {
public:
    DefaultOnlineLightsCap(shared_ptr<PubSubDataConnector> dataConnector,
                           const uint8_t &pin,
                           const string &name = "Default-online-lights-cap",
                           uint32_t pwmRange = DEFAULT_PWM_RANGE
    );

    ~DefaultOnlineLightsCap() = default;

    void execute() override;

    void sendData() {
        LightsData::sendData(this);
    }

    void initDataHandler(LightsCap *cap){

    }
};


#endif //BARTOS_HW_DEFAULTONLINELIGHTSCAP_H
