#ifndef LIGHTS_CAP_H
#define LIGHTS_CAP_H

#include <PowerAbleCap.h>

#include <string>

#define DEFAULT_PWM_RANGE 1024

class LightsCap : public PowerAbleCap {
   protected:
    uint8_t _intensity;
    uint32_t _pwmRange;

   public:
    LightsCap(const uint8_t &pin,
              uint32_t pwmRange = DEFAULT_PWM_RANGE);

    ~LightsCap() = default;

    virtual void turnOn() override;

    virtual void turnOff() override;

    virtual bool isTurnedOn() override;

    virtual void changeIntensity(uint8_t intensity) = 0;

    virtual void increaseIntensity();

    virtual void decreaseIntensity();

    virtual uint8_t getActualIntensity();

    uint32_t getPwmRange();

    void setPwmRange(uint32_t range);

    static bool validIntensity(uint8_t intensity);
};

#endif  // LIGHTS_CAP_H