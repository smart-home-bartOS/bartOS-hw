#include "Capability.h"

Capability::Capability(const uint8_t &pin, CapabilityType type) : StateConnection(ConnectionType::OFFLINE),
                                                                  _pin(pin),
                                                                  _type(type) {
}

Capability::Capability(const uint8_t &pin, CapabilityType type, const unsigned sampleTime) : Capability(pin, type) {
    setSampleTime(sampleTime);
}

long Capability::getID() {
    return _ID;
}
void Capability::setID(const long &id) {
    _ID = id;
}

string Capability::getNameID() {
    return _nameID;
}

void Capability::setNameID(const string &nameID) {
    _nameID = nameID;
}

shared_ptr<Device> Capability::getDevice() {
    return _device;
}

void Capability::setDevice(shared_ptr<Device> device) {
    _device = device;
}

//VIRTUAL
void Capability::init() {}

void Capability::preExecute() {
    if (isSampleTimeAchieved()) {
        execute();
    }
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

CapabilityType Capability::getType() {
    return _type;
}

void Capability::setType(CapabilityType &type) {
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
