#ifndef HUMIDITY_CAP_H
#define HUMIDITY_CAP_H

#include <core/capability/Capability.h>

class HumidityCap : public Capability {
private:
    uint8_t _humidity;
public:
    explicit HumidityCap(const uint8_t &pin);

    HumidityCap(const uint8_t &pin, const string &name);

    HumidityCap(const uint8_t &pin, unsigned sampleTime);

    HumidityCap(const uint8_t &pin, const string &name, unsigned sampleTime);

    ~HumidityCap() = default;

    uint8_t getHumidity();

    void setHumidity(const uint8_t &hum);
};

#endif  // HUMIDITY_CAP_H