
#include "device/Device.h"

#include <Arduino.h>

#include <string>

#include "device/DeviceFields.h"
using std::make_shared;

Device::Device() {
    _scheduler = make_shared<TimeActionMap>();
}

void Device::init() {
    initCapabilities();
}

void Device::loop() {
    _scheduler->loop();
    loopCapabilities();
}

/* CAPS */
vector<shared_ptr<Capability>> Device::getCapabilities() {
    return _capabilities;
}

void Device::setCapabilities(vector<shared_ptr<Capability>> &caps) {
    _capabilities = caps;
}

shared_ptr<Capability> Device::getCapByPinAndType(const uint8_t &pin, const std::string &type) {
    for (auto &item : getCapabilities()) {
        if (item->getPin() == pin && item->getType() == type) {
            return item;
        }
    }
    return nullptr;
}

void Device::initCapabilities() {
    Serial.printf("Init all capabilities. Count: %d\n", getCapabilities().size());

    for (auto &item : getCapabilities()) {
        if (item->isEnabled()) {
            item->printInfo();
            item->init();
        }
    }
}

void Device::loopCapabilities() {
    for (auto &item : getCapabilities()) {
        if (item->isEnabled()) {
            item->loop();
        }
    }
}

void Device::factoryReset() {
    Serial.println("Reset device");
    delay(2000);
    ESP.restart();
    delay(3000);
}

unsigned long Device::getDeviceMillis() {
    return millis();
}

void Device::changeCapabilityState(bool state) {
    for (auto &item : getCapabilities()) {
        item->setEnabled(state);
    }
}

void Device::disableCapabilities() {
    changeCapabilityState(false);
}

void Device::enableCapabilities() {
    changeCapabilityState(true);
}