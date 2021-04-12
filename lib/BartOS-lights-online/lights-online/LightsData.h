//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_LIGHTSDATA_H
#define BARTOS_HW_LIGHTSDATA_H

#include <lights/LightsCap.h>
#include <online-device/capability/PubSubDataTransceiver.h>

class LightsData : public PubSubDataTransceiver {
public:
    static const char *INTENSITY;

    LightsData(shared_ptr<PubSubDataConnector> dataConnector);

    ~LightsData() = default;

    void sendData(LightsCap *cap);
};


#endif //BARTOS_HW_LIGHTSDATA_H
