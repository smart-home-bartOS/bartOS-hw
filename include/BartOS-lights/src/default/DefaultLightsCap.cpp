//
// Created by mabartos on 4/6/21.
//

#include "default/DefaultLightsCap.h"
#include <Arduino.h>

DefaultLightsCap::DefaultLightsCap(const uint8_t &pin, const string &name, uint32_t pwmRange) :
        LightsCap(pin, name, pwmRange) {
}

void DefaultLightsCap::init() {
    pinMode(_pin, OUTPUT);
    turnOff();
}

void DefaultLightsCap::execute() {
    checkSmoothIntensity();
}

void DefaultLightsCap::turnOn() {
    LightsCap::turnOn();
    isSmoothModeEnabled() ? changeSmoothIntensity(100) : digitalWrite(_pin, isInverseOutput() ? LOW : HIGH);
}

void DefaultLightsCap::turnOff() {
    LightsCap::turnOff();
    isSmoothModeEnabled() ? changeSmoothIntensity(0) : digitalWrite(_pin, isInverseOutput() ? HIGH : LOW);
}

void DefaultLightsCap::executeChangeIntensity(uint8_t intensity) {
    if (!validIntensity(intensity))return;
    if (intensity == 0) {
        turnOff();
        return;
    }
    setTurnedOn(true);
    float resultIntensity = (getPwmRange() / 100.0) * intensity;
    analogWrite(_pin, (uint16_t) resultIntensity);
    _intensity = intensity;
}

void DefaultLightsCap::changeIntensity(uint8_t intensity) {
    if (isSmoothModeEnabled()) {
        changeSmoothIntensity(intensity);
        return;
    }

    if (intensity >= 100) {
        _intensity = 100;
        turnOn();
        return;
    }
    executeChangeIntensity(intensity);
}

void DefaultLightsCap::checkSmoothIntensity() {
    if (isSmoothModeEnabled()) {
        if (_intensity == _resultIntensity) {
            setSampleTime(0);
            smoothMode(false);
            return;
        }
        _intensity < _resultIntensity ? _intensity++ : _intensity--;
        changeIntensity(_intensity);
    }
}

void DefaultLightsCap::changeSmoothIntensity(uint8_t intensity) {
    smoothMode(true);
    setSampleTime(getSmoothSampleInterval());
    _resultIntensity = intensity;
}

void DefaultLightsCap::smoothMode(bool state) {
    _smoothMode = state;
}

bool DefaultLightsCap::isSmoothModeEnabled() {
    return _smoothMode;
}

void DefaultLightsCap::setSmoothSampleInterval(uint32_t interval) {
    _smoothSampleInterval = interval;
}

uint32_t DefaultLightsCap::getSmoothSampleInterval() {
    return _smoothSampleInterval;
}