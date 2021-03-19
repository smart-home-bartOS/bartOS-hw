
#include "Device.h"

#include <Arduino.h>

#include <string>

#include "DeviceFields.h"
#include "core/generator/NumberGenerator.h"
#include "core/storage/FsManager.h"

FsManager fsManager;

Device::Device() : StateConnection(ConnectionType::OFFLINE) {
    setName("Dev_" + NumberGenerator::generateIntToString(2000, 9999));
}

string Device::getName() {
    return _name;
}

void Device::setName(const string &name) {
    _name = name;
}

long Device::getID() {
    return _id;
}

void Device::setID(const long &id) {
    _id = id;
}

long Device::getHomeID() {
    return _homeID;
}

void Device::setHomeID(const long &homeID) {
    _homeID = homeID;
}

long Device::getRoomID() {
    return _roomID;
}

void Device::setRoomID(const long &roomID) {
    _roomID = roomID;
}

bool Device::isInitialized() {
    return _initialized;
}

void Device::setInitialized(bool initialized) {
    _initialized = initialized;
}

/* CAPS */
vector<Capability &> Device::getCapabilities() {
    return _capabilities;
}

auto Device::getCapByPin(const uint8_t &pin) -> shared_ptr<Capability> {
    for (auto &item : getCapabilities()) {
        if (item->getPin() == pin) {
            return item;
        }
    }
    return nullptr;
}

void Device::addCapability(Capability &cap) {
    _capabilities.push_back(cap);
}

void Device::removeCapability(long id) {
    vector<Capability &> caps = getCapabilities();
    for (unsigned i = 0; i < caps.size(); i++) {
        if (caps[i].getID() == id) {
            _capabilities.erase(caps.begin() + i);
        }
    }
}

void Device::removeCapabilityByPin(const uint8_t &pin) {
    vector<Capability &> caps = getCapabilities();
    for (unsigned i = 0; i < caps.size(); i++) {
        if (caps[i]->getPin() == pin) {
            _capabilities.erase(caps.begin() + i);
        }
    }
}

void Device::initAllCapabilities() {
    for (Capability &item : getCapabilities()) {
        item->init();
    }
}

void Device::executeAllCapabilities() {
    for (Capability item : getCapabilities()) {
        item.execute();
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