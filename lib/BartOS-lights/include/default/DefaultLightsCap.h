//
// Created by mabartos on 4/6/21.
//

#ifndef BARTOS_HW_DEFAULTLIGHTSCAP_H
#define BARTOS_HW_DEFAULTLIGHTSCAP_H

#include "LightsCap.h"

#define DEFAULT_PWM_RANGE 1024
#define DEFAULT_SMOOTH_SAMPLE_INTERVAL 1000  // time for smooth executing in milliseconds
#define DEFAULT_MAX_SMOOTH_DELAY 300         // maximal value for sample time

/**
 * @author Nikola Polova
 * @author Martin Bartos
 */
class DefaultLightsCap : public LightsCap {
   private:
    bool _smoothActive = false;
    uint32_t _smoothSampleInterval = DEFAULT_SMOOTH_SAMPLE_INTERVAL;
    uint32_t _maxSmoothDelay = DEFAULT_MAX_SMOOTH_DELAY;
    bool _smoothMode = false;

   protected:
    uint8_t _resultIntensity = 0;

    void executeChangeIntensity(uint8_t intensity);

    void changeSmoothIntensity(uint8_t intensity);

    void checkSmoothIntensity();

    void forceTurnOn();

    void forceTurnOff();

    uint32_t getMaxSmoothDelay();

    void setMaxSmoothDelay(uint32_t delay);

   public:
    DefaultLightsCap(const uint8_t &pin,
                     uint32_t pwmRange = DEFAULT_PWM_RANGE);

    ~DefaultLightsCap() = default;

    void init() override;

    void loop() override;

    void turnOn() override;

    void turnOff() override;

    void changeIntensity(uint8_t intensity) override;

    uint8_t getActualIntensity() override;

    void smoothMode(bool state);

    bool isSmoothModeEnabled();

    void setSmoothSampleInterval(uint32_t interval);

    uint32_t getSmoothSampleInterval();
};

#endif  // BARTOS_HW_DEFAULTLIGHTSCAP_H
