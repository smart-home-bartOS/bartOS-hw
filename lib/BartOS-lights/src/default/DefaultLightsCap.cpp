//
// Created by mabartos on 4/6/21.
//

#include "default/DefaultLightsCap.h"

#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>

DefaultLightsCap::DefaultLightsCap(const uint8_t &pin,
                                   const string &name,
                                   uint32_t pwmRange) : LightsCap(pin, name, pwmRange) {
}

void DefaultLightsCap::init() {
    pinMode(_pin, OUTPUT);
    forceTurnOff();
}

void DefaultLightsCap::loop() {
    checkSmoothIntensity();
}

void DefaultLightsCap::turnOn() {
    isSmoothModeEnabled() ? changeSmoothIntensity(100) : forceTurnOn();
}

void DefaultLightsCap::turnOff() {
    isSmoothModeEnabled() ? changeSmoothIntensity(0) : forceTurnOff();
}

void DefaultLightsCap::forceTurnOn() {
    LightsCap::turnOn();
    digitalWrite(_pin, isInverseOutput() ? LOW : HIGH);
}

void DefaultLightsCap::forceTurnOff() {
    LightsCap::turnOff();
    digitalWrite(_pin, isInverseOutput() ? HIGH : LOW);
}

uint8_t DefaultLightsCap::getActualIntensity() {
    return isSmoothModeEnabled() ? _resultIntensity : _intensity;
}

void DefaultLightsCap::executeChangeIntensity(uint8_t intensity) {
    if (intensity > 100) {
        intensity = 100;
    } else if (intensity == 0) {
        forceTurnOff();
        return;
    }

    setTurnedOn(true);
    float resultIntensity = (getPwmRange() / 100.0) * intensity;
    analogWrite(_pin, (uint16_t)resultIntensity);
    _intensity = intensity;
}

void DefaultLightsCap::changeIntensity(uint8_t intensity) {
    if (isSmoothModeEnabled()) {
        changeSmoothIntensity(intensity);
        return;
    }

    executeChangeIntensity(intensity);
}

void DefaultLightsCap::checkSmoothIntensity() {
    if (isSmoothModeEnabled() && _smoothActive) {
        if (_intensity == _resultIntensity) {
            setSampleTime(0);
            _smoothActive = false;
            return;
        }
        _intensity < _resultIntensity ? _intensity++ : _intensity--;
        executeChangeIntensity(_intensity);
    }
}

void DefaultLightsCap::changeSmoothIntensity(uint8_t intensity) {
    uint32_t samplesCount = abs(intensity - _intensity);
    unsigned sampleTime = getSmoothSampleInterval() / samplesCount;
    sampleTime = sampleTime > getMaxSmoothDelay() ? getMaxSmoothDelay() : sampleTime;

    setSampleTime(sampleTime);
    _resultIntensity = intensity;
    _smoothActive = true;
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

uint32_t DefaultLightsCap::getMaxSmoothDelay() {
    return _maxSmoothDelay;
}

void DefaultLightsCap::setMaxSmoothDelay(uint32_t delay) {
    _maxSmoothDelay = delay;
}