#include "Capability.h"

#include <utility>
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

shared_ptr<Device> Capability::getDevice() {
    return _device;
}

void Capability::setDevice(shared_ptr<Device> device) {
    _device = move(device);
}

//VIRTUAL
void Capability::init() {}

void Capability::preExecute() {
    if (isSampleTimeAchieved()) {
        execute();
        eventHandlerExecute()->executeAll();
    }
    eventHandlerLoop()->executeAll();
}

void Capability::execute() {}

uint8_t Capability::getPin() {
    return _pin;
}

void Capability::setPin(const uint8_t &pin) {
    _pin = pin;
}

bool Capability::isEnabled() {
    return _enable;
}

string Capability::getType() {
    return _type;
}

void Capability::setType(const string &type) {
    _type = type;
}

unsigned Capability::getSampleTime() {
    return _sampleTime;
}

void Capability::setSampleTime(unsigned millis) {
    _sampleTime = millis;
}

bool Capability::isSampleTimeAchieved() {
    Device *device = getDevice().get();
    const unsigned sampleTime = getSampleTime();

    if (sampleTime == 0 || device == nullptr) {
        return true;
    }

    if ((device->getDeviceMillis() - _lastExecution) >= sampleTime) {
        _lastExecution = device->getDeviceMillis();
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
