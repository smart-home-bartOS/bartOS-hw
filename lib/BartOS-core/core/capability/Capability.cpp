#include "Capability.h"

#include <Arduino.h>

Capability::Capability(const uint8_t &pin,
                       const string &type,
                       const string &name,
                       const unsigned sampleTime) :
        StateConnection(ConnectionType::OFFLINE),
        _pin(pin),
        _name(name),
        _type(type),
        _sampleTime(sampleTime) {
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
    if (isSampleTimeAchieved()) {
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
    const unsigned long sampleTime = getSampleTime();

    if (sampleTime == 0) {
        return true;
    }

    if ((getActualMillis() - _lastExecution) >= sampleTime) {
        _lastExecution = getActualMillis();
        return true;
    }
    return false;
}

shared_ptr<CallbackMap> Capability::executeEventHandler() {
    return _execCallbackMap;
}

shared_ptr<CallbackMapTime> Capability::loopEventHandler() {
    return _loopCallbackMap;
}
