//
// Created by mabartos on 4/13/21.
//

#ifndef BARTOS_HW_DHTTEMPONLINE_H
#define BARTOS_HW_DHTTEMPONLINE_H

#include <default/DhtTempSensor.h>
#include "TemperatureData.h"

class DhtTempOnline : public DhtTempSensor, public TemperatureData {
public:
    DhtTempOnline(shared_ptr<PubSubDataConnector> dataConnector,
                  const uint8_t &pin,
                  const uint8_t &dhtType,
                  const string &name = DEFAULT_NAME);

    ~DhtTempOnline() = default;

    void execute();

    void sendData() {
        TemperatureData::sendData(this);
    }
};


#endif //BARTOS_HW_DHTTEMPONLINE_H
