#include "capability/Capability.h"

#include <Arduino.h>
using std::make_shared;

Capability::Capability(const uint8_t &pin,
                       const std::string &type,
                       const unsigned sampleTime) : _sampleTime(sampleTime),
                                                    _pin(pin),
                                                    _type(type) {
    _actions = make_shared<ActionMap>();
    _scheduler = make_shared<TimeActionMap>();
}

// VIRTUAL
void Capability::init() {}
void Capability::loop() {}

void Capability::priorLoop() {
    if (isSampleTimeAchieved() && isDelayTimeAchieved()) {
        loop();
        scheduler()->loop();
    }
    actions()->loop();
}

uint8_t Capability::getPin() {
    return _pin;
}

void Capability::setPin(const uint8_t &pin) {
    _pin = pin;
}

bool Capability::isEnabled() {
    return _enabled;
}

void Capability::setEnabled(bool enabled) {
    _enabled = enabled;
}

void Capability::enable() {
    setEnabled(true);
}

void Capability::disable() {
    setEnabled(false);
}

string Capability::getType() {
    return _type;
}

void Capability::setType(const std::string &type) {
    _type = type;
}

unsigned long Capability::getSampleTime() {
    return _sampleTime;
}

void Capability::setSampleTime(unsigned millis) {
    _sampleTime = millis;
}

unsigned long Capability::getActualMillis() {
    return millis();
}

bool Capability::isSampleTimeAchieved() {
    if (getSampleTime() == 0) {
        return true;
    }

    if ((getActualMillis() - _lastExecution) >= getSampleTime()) {
        _lastExecution = getActualMillis();
        return true;
    }
    return false;
}

bool Capability::isDelayTimeAchieved() {
    if (_delayTime == 0) {
        return true;
    }

    if ((getActualMillis() - _delayLastExecution) >= _delayTime) {
        _delayLastExecution = getActualMillis();
        _delayTime = 0;
        return true;
    }
    return false;
}

void Capability::delayExecution(unsigned long time) {
    _delayTime = time;
}

shared_ptr<ActionMap> Capability::actions() {
    return _actions;
}

shared_ptr<TimeActionMap> Capability::scheduler() {
    return _scheduler;
}

void Capability::printInfo() {
    Serial.printf("Cap = type:'%s', pin:'%d'.\n", getType().c_str(), getPin());
}