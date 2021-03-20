//
// Created by mabartos on 3/20/21.
//

#ifndef BARTOS_HW_DHTTEMPSENSOR_H
#define BARTOS_HW_DHTTEMPSENSOR_H

#include <temp/TemperatureCap.h>

class DhtTempSensor : public TemperatureCap {
public:
    explicit DhtTempSensor(const uint8_t &pin);

    ~DhtTempSensor() = default;

    void init() override;

    void execute() override;
};

#endif //BARTOS_HW_DHTTEMPSENSOR_H
