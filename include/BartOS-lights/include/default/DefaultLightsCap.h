//
// Created by mabartos on 4/6/21.
//

#ifndef BARTOS_HW_DEFAULTLIGHTSCAP_H
#define BARTOS_HW_DEFAULTLIGHTSCAP_H

#include "LightsCap.h"

#define DEFAULT_PWM_RANGE 1024
#define DEFAULT_SMOOTH_SAMPLE_INTERVAL 15 // time for smooth executing in milliseconds

/**
 * @author Nikola Polova
 * @author Martin Bartos
 */
class DefaultLightsCap : public LightsCap {
protected:
    uint8_t _resultIntensity = 0;
    bool _smoothMode = false;
    uint32_t _smoothSampleInterval = DEFAULT_SMOOTH_SAMPLE_INTERVAL;

    void executeChangeIntensity(uint8_t intensity);

    void changeSmoothIntensity(uint8_t intensity);

    void checkSmoothIntensity();

public:
    DefaultLightsCap(const uint8_t &pin,
                     const string &name = "Default-lights-cap",
                     uint32_t pwmRange = DEFAULT_PWM_RANGE);

    ~DefaultLightsCap() = default;

    void init() override;

    void execute() override;

    void turnOn() override;

    void turnOff() override;

    void changeIntensity(uint8_t intensity) override;

    void smoothMode(bool state);

    bool isSmoothModeEnabled();

    void setSmoothSampleInterval(uint32_t interval);

    uint32_t getSmoothSampleInterval();
};


#endif //BARTOS_HW_DEFAULTLIGHTSCAP_H
