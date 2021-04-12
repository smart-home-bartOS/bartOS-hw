//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_HUMIDITYDATA_H
#define BARTOS_HW_HUMIDITYDATA_H

#include <online-device/capability/PubSubDataTransceiver.h>
#include <humidity/HumidityCap.h>

class HumidityData : public PubSubDataTransceiver {
public:
    static const char *HUMIDITY_FIELD;
    static const char *UNITS_FIELD;

    HumidityData(shared_ptr<PubSubDataConnector> dataConnector);

    ~HumidityData() = default;

    void sendData(HumidityCap *cap);
};


#endif //BARTOS_HW_HUMIDITYDATA_H
