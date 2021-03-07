
#include "Device.h"

#include <string>

#include "DeviceFields.h"
#include "capability/general/CapabilityFields.h"
#include "capability/utils/CapabilityUtils.h"
#include "storage/FsManager.h"
#include "wifiUtils/WifiUtils.h"

FsManager fsManager;

Device::Device() {
    setName("Dev_" + NumberGenerator::generateIntToString(2000, 9999));
}

string Device::getName() {
    return _name;
}

void Device::setName(const string &name) {
    _name = name;
}

long Device::getID() {
    return _ID;
}
void Device::setID(const long &id) {
    _ID = id;
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

auto Device::getCapByPinAndType(const uint8_t &pin, const CapabilityType &type) -> shared_ptr<Capability> {
    for (auto &item : getCapabilities()) {
        if (item->getPin() == pin && item->getType() == type) {
            return item;
        }
    }
    return nullptr;
}

void Device::addCapability(shared_ptr<Capability> cap) {
    _capabilities.push_back(cap);
}

void Device::removeCapability(long id) {
    vector<shared_ptr<Capability>> caps = getCapabilities();
    for (unsigned i = 0; i < caps.size(); i++) {
        if (caps[i]->getID() == id) {
            _capabilities.erase(caps.begin() + i);
        }
    }
}

void Device::initAllCapabilities() {
    for (auto &item : getCapabilities()) {
        item->init();
    }
}

void Device::executeAllCapabilities() {
    for (auto &item : getCapabilities()) {
        item->execute();
    }
}
void Device::setCapsIDFromJSON(const JsonObject &obj, bool shouldCreate) {
    if (obj.containsKey(CAPABILITIES)) {
        StaticJsonDocument<1024> doc;

        JsonArray caps = obj[CAPABILITIES];

        for (JsonObject cap : caps) {
            long capID = cap[ID];
            uint8_t pin = cap[PIN];
            const char *type = cap[TYPE];

            auto p_cap = getCapByPinAndType(pin, CapabilityUtils::getFromString(string(type)));
            if (p_cap != nullptr) {
                p_cap->setID(capID);
            }
        }
        doc.garbageCollect();
    }
}

void Device::setCapsIDFromJSON(const JsonObject &obj) {
    setCapsIDFromJSON(obj, false);
}

void Device::eraseAll() {
    Serial.println("Reset device");
    delay(2000);
    ESP.restart();
    delay(3000);
}