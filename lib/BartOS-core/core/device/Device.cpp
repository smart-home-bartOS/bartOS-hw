
#include "Device.h"

#include <Arduino.h>

#include <string>

#include "DeviceFields.h"
#include "core/generator/NumberGenerator.h"

Device::Device(vector<shared_ptr<Capability>> capabilities) : StateConnection(ConnectionType::OFFLINE),
                                                              _capabilities(move(capabilities)) {
    setName("Dev_" + NumberGenerator::generateIntToString(2000, 9999));
}

void Device::init() {}

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
vector<shared_ptr<Capability>> Device::getCapabilities() {
    return _capabilities;
}

void Device::setCapabilities(vector<shared_ptr<Capability>> &caps) {
    _capabilities = caps;
}

auto Device::getCapByPin(const uint8_t &pin) -> shared_ptr<Capability> {
    for (auto &item : getCapabilities()) {
        if (item->getPin() == pin) {
            return item;
        }
    }
    return nullptr;
}

void Device::printCapabilityInfo(const shared_ptr<Capability> &cap) {
    Serial.print("INIT: type: '");
    Serial.print(cap->getType().c_str());
    Serial.print("', name:'");
    Serial.print(cap->getName().c_str());
    Serial.println("'.");
}

void Device::initAllCapabilities() {
    Serial.println("Init All capabilities");
    Serial.print("Number of caps:");
    Serial.println(getCapabilities().size());

    for (auto &item : getCapabilities()) {
        printCapabilityInfo(item);
        if (item->isEnabled()) {
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