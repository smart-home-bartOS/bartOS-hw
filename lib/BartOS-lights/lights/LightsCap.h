#ifndef LIGHTS_CAP_H
#define LIGHTS_CAP_H
using namespace std;

#include <string>
#include "core/capability/Capability.h"

#define DEFAULT_PWM_RANGE 1024

class LightsCap : public Capability {
protected:
    uint8_t _intensity;
    uint32_t _pwmRange;
    bool _isTurnedOn;
public:
    LightsCap(const uint8_t &pin,
              const string &name = "Lights-cap",
              uint32_t pwmRange = DEFAULT_PWM_RANGE);

    ~LightsCap() = default;

    virtual void turnOn();

    virtual void turnOff();

    virtual void changeIntensity(uint8_t intensity) = 0;

    uint8_t getActualIntensity();

    uint32_t getPwmRange();

    void setPwmRange(uint32_t range);

    virtual bool isTurnedOn();

    void setIsTurnedOn(bool state);

    void switchState();
};

#endif  //LIGHTS_CAP_H