//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_LIGHTSDATA_H
#define BARTOS_HW_LIGHTSDATA_H

#include <LightsCap.h>
#include <transceiver/PubSubDataTransceiver.h>

class LightsData : public PubSubDataTransceiver {
public:
    static const char *INTENSITY;
    static const char *STATE;

    LightsData(shared_ptr<PubSubDataConnector> dataConnector);

    ~LightsData() = default;

    void sendData(LightsCap *cap);

    void initDataHandler(LightsCap *cap,
                         long deviceID = -1,
                         long homeID = -1,
                         long roomID = -1);
};


#endif //BARTOS_HW_LIGHTSDATA_H
