//
// Created by mabartos on 3/20/21.
//

#ifndef BARTOS_HW_DHTTEMPSENSOR_H
#define BARTOS_HW_DHTTEMPSENSOR_H

#include <Adafruit_Sensor.h>
#include <DHT.h>

#include <memory>

#include "TemperatureCap.h"

using namespace std;

class DhtTempSensor : public TemperatureCap {
   protected:
    shared_ptr<DHT> _dht;
    uint8_t _dhtType;

    bool isValidDHT();

   public:
    static const char *DEFAULT_NAME;

    DhtTempSensor(const uint8_t &pin, const uint8_t &dhtType);

    ~DhtTempSensor() = default;

    void init() override;

    void loop() override;

    uint8_t getDhtType();
};

#endif  // BARTOS_HW_DHTTEMPSENSOR_H
