#ifndef TEMPERATURE_CAP_H
#define TEMPERATURE_CAP_H

#include <string>

#include "core/capability/CapabilityWithValue.h"

using namespace std;

#define DEFAULT_SAMPLE_TIME_MS 300

class TemperatureCap : public CapabilityWithValue<double, string> {
   public:
    TemperatureCap(const string &name, const uint8_t &pin, const unsigned sampleTime);
    TemperatureCap(const string &name, const uint8_t &pin);
    ~TemperatureCap() = default;

    void init();
    void execute();
};

#endif  // TEMPERATURE_CAP_H