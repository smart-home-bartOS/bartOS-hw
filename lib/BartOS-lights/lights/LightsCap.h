#ifndef LIGHTS_CAP_H
#define LIGHTS_CAP_H
using namespace std;

#include <string>
#include "core/capability/Capability.h"

#define DEFAULT_PWM_RANGE 1024

class LightsCap : public Capability {
protected:
    uint8_t _intensity;
    uint32_t _pwm_range;
public:
    LightsCap(const uint8_t &pin,
              const string &name = "Lights-cap",
              uint32_t pwmRange = DEFAULT_PWM_RANGE);

    ~LightsCap() = default;

    virtual void turnOn() = 0;

    virtual void turnOff() = 0;

    virtual void changeIntensity(uint8_t intensity) = 0;

    uint8_t getActualIntensity();

    uint32_t getPwmRange();

    void setPwmRange(uint32_t range);
};

#endif  //LIGHTS_CAP_H