#ifndef DEVICE_H
#define DEVICE_H

#include <ArduinoJson.h>

#include <memory>
#include <string>
#include <vector>

#include "capability/general/Capability.h"
#include "generator/NumberGenerator.h"

using namespace std;

class Device {
   private:
    string _name;
    long _ID = -1;
    long _homeID = -1;
    long _roomID = -1;

    bool _initialized = false;

    vector<shared_ptr<Capability>> _capabilities;

   public:
    Device();
    ~Device() = default;

    virtual void init();

    string getName();
    void setName(const string &name);

    long getID();
    void setID(const long &id);

    long getHomeID();
    void setHomeID(const long &homeID);

    long getRoomID();
    void setRoomID(const long &roomID);

    bool isInitialized();
    void setInitialized(bool initialized);

    /* CAPS */
    vector<shared_ptr<Capability>> getCapabilities();
    void setCapabilities(vector<shared_ptr<Capability>> &caps);

    void setCapsIDFromJSON(const JsonObject &obj);
    void setCapsIDFromJSON(const JsonObject &obj, bool shouldCreate);

    auto getCapByPinAndType(const uint8_t &pin, const CapabilityType &type) -> shared_ptr<Capability>;

    void addCapability(shared_ptr<Capability> cap);

    void removeCapability(long id);

    void initAllCapabilities();

    void executeAllCapabilities();

    void eraseAll();
};

#endif  // DEVICE_H