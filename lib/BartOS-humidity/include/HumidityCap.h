#ifndef HUMIDITY_CAP_H
#define HUMIDITY_CAP_H

#include <capability/Capability.h>

#define DEFAULT_SAMPLE_TIME_MS 300

class HumidityCap : public Capability {
   private:
    uint8_t _humidity;

   public:
    HumidityCap(const uint8_t &pin, unsigned sampleTime = DEFAULT_SAMPLE_TIME_MS);

    ~HumidityCap() = default;

    uint8_t getHumidity();

    void setHumidity(const uint8_t &hum);
};

#endif  // HUMIDITY_CAP_H