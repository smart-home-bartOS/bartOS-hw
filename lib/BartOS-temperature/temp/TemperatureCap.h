#ifndef TEMPERATURE_CAP_H
#define TEMPERATURE_CAP_H

#include <string>

#include "core/capability/Capability.h"
using namespace std;

#define DEFAULT_SAMPLE_TIME_MS 300

class TemperatureCap : public Capability {
   private:
    float _temp;
    string _units = "°C";

   public:
    TemperatureCap(const uint8_t &pin);
    TemperatureCap(const uint8_t &pin, const string &name);
    TemperatureCap(const uint8_t &pin, const unsigned sampleTime);
    TemperatureCap(const uint8_t &pin, const string &name, const unsigned sampleTime);
    ~TemperatureCap() = default;

    void init() override;
    void execute() override;

    float getTemperature();
    void setTemperature(const float &temp);

    string getUnits();
    void setUnits(const string &units);
};

#endif  // TEMPERATURE_CAP_H