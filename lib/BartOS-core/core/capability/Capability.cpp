#include "Capability.h"

#include <Arduino.h>

Capability::Capability(const uint8_t &pin,
                       const string &type,
                       const string &name,
                       const unsigned sampleTime) :
        StateConnection(ConnectionType::OFFLINE),
        _sampleTime(sampleTime),
        _pin(pin),
        _name(name),
        _type(type) {
    _loopCallbackMap = make_shared<CallbackMapTime>();
    _execCallbackMap = make_shared<CallbackMap>();
}

long Capability::getID() {
    return _ID;
}

void Capability::setID(const long &id) {
    _ID = id;
}

string Capability::getName() {
    return _name;
}

void Capability::setName(const string &name) {
    _name = name;
}

//VIRTUAL
void Capability::init() {}

void Capability::preExecute() {
    if (isSampleTimeAchieved() && isDelayTimeAchieved()) {
        execute();
        executeEventHandler()->executeAll();
    }
    loopEventHandler()->executeAll();
}

void Capability::execute() {}

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

string Capability::getType() {
    return _type;
}

void Capability::setType(const string &type) {
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

shared_ptr<CallbackMap> Capability::executeEventHandler() {
    return _execCallbackMap;
}

shared_ptr<CallbackMapTime> Capability::loopEventHandler() {
    return _loopCallbackMap;
}
