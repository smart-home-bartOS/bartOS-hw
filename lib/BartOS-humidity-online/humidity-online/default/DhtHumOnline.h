//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_DHTHUMONLINE_H
#define BARTOS_HW_DHTHUMONLINE_H

#include <humidity/default/DhtHumSensor.h>
#include <humidity-online/HumidityData.h>

class DhtHumOnline : public DhtHumSensor, public HumidityData {
public:
    DhtHumOnline(shared_ptr<PubSubDataConnector> dataConnector,
                 const uint8_t &pin,
                 const uint8_t &dhtType,
                 const string &name = DEFAULT_NAME);

    ~DhtHumOnline() = default;

    void execute();

    void sendData() {
        HumidityData::sendData(this);
    }
};


#endif //BARTOS_HW_DHTHUMONLINE_H
