//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_DHTHUMSENSOR_H
#define BARTOS_HW_DHTHUMSENSOR_H

#include <humidity/HumidityCap.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <memory>

class DhtHumSensor : public HumidityCap {
protected:
    shared_ptr<DHT> _dht;
    uint8_t _dhtType;

    bool isValidDHT();

public:
    static const char *DEFAULT_NAME;

    DhtHumSensor(const uint8_t &pin, const uint8_t &dhtType, const string &name = DEFAULT_NAME);

    ~DhtHumSensor() = default;

    void init() override;

    void execute() override;

    uint8_t getDhtType();
};


#endif //BARTOS_HW_DHTHUMSENSOR_H
