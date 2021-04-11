//
// Created by mabartos on 4/6/21.
//

#ifndef BARTOS_HW_DEFAULTLIGHTSCAP_H
#define BARTOS_HW_DEFAULTLIGHTSCAP_H

#include <lights/LightsCap.h>

#define DEFAULT_PWM_RANGE 1024

class DefaultLightsCap : public LightsCap {
public:
    DefaultLightsCap(const uint8_t &pin,
                     const string &name = "Default-lights-cap",
                     uint32_t pwmRange = DEFAULT_PWM_RANGE);

    ~DefaultLightsCap() = default;

    void init();

    void turnOn();

    void turnOff();

    bool isTurnedOn();

    void changeIntensity(uint8_t intensity);
};


#endif //BARTOS_HW_DEFAULTLIGHTSCAP_H
