#ifndef TEMPERATURE_CAP_H
#define TEMPERATURE_CAP_H

#include <string>

#include <capability/Capability.h>

using namespace std;

#define DEFAULT_SAMPLE_TIME_MS 300

class TemperatureCap : public Capability {
private:
    float _temp = 0.0f;
    string _units = "°C";
public:
    TemperatureCap(const uint8_t &pin,
                   const string &name = "Temp-cap",
                   unsigned sampleTime = DEFAULT_SAMPLE_TIME_MS);

    ~TemperatureCap() = default;

    float getTemperature();

    void setTemperature(const float &temp);

    string getUnits();

    void setUnits(const string &units);
};

#endif  // TEMPERATURE_CAP_H