
#include "Device.h"

#include <Arduino.h>

#include <string>

#include "DeviceFields.h"

Device::Device(const string &name) : StateConnection(ConnectionType::OFFLINE),
                                     _name(name) {
}

void Device::init() {
    initAllCapabilities();
    setInitialized(true);
}

void Device::loop() {
    executeAllCapabilities();
}

string Device::getName() {
    return _name;
}

void Device::setName(const string &name) {
    _name = name;
}

bool Device::isInitialized() {
    return _initialized;
}

void Device::setInitialized(bool initialized) {
    _initialized = initialized;
}

/* CAPS */
vector<shared_ptr<Capability>> Device::getCapabilities() {
    return _capabilities;
}

void Device::setCapabilities(vector<shared_ptr<Capability>> &caps) {
    _capabilities = caps;
}

shared_ptr<Capability> Device::getCapByPinAndType(const uint8_t &pin, const string &type) {
    for (auto &item : getCapabilities()) {
        if (item->getPin() == pin && item->getType() == type) {
            return item;
        }
    }
    return nullptr;
}

void Device::initAllCapabilities() {
    Serial.printf("Init all capabilities. Count: %d\n", getCapabilities().size());

    for (auto &item : getCapabilities()) {
        if (item->isEnabled()) {
            item->printInfo();
            item->init();
        }
    }
}

void Device::executeAllCapabilities() {
    for (auto &item : getCapabilities()) {
        if (item->isEnabled()) {
            item->preExecute();
        }
    }
}

void Device::eraseAll() {
    Serial.println("Reset device");
    delay(2000);
    ESP.restart();
    delay(3000);
}

unsigned long Device::getDeviceMillis() {
    return millis();
}

void Device::changeCapAvailability(bool state) {
    for (auto &item : getCapabilities()) {
        item->setEnabled(state);
    }
}

void Device::disableAllCapabilities() {
    changeCapAvailability(false);
}

void Device::enableAllCapabilities() {
    changeCapAvailability(true);
}