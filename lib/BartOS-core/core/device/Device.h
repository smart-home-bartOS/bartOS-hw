#ifndef DEVICE_H
#define DEVICE_H

#include <memory>
#include <string>
#include <vector>

#include "core/StateConnection.h"
#include "core/capability/Capability.h"
#include "core/generator/NumberGenerator.h"

using namespace std;

class Device : public StateConnection {
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

    auto getCapByPin(const uint8_t &pin) -> shared_ptr<Capability>;

    void addCapability(shared_ptr<Capability> cap);

    void removeCapability(long id);

    void removeCapabilityByPin(const uint8_t &pin);

    void initAllCapabilities();

    void executeAllCapabilities();

    void eraseAll();

    virtual unsigned long getDeviceMillis();
};

#endif  // DEVICE_H