#ifndef DEVICE_H
#define DEVICE_H

#include <memory>
#include <string>
#include <vector>
#include <core/StateConnection.h>
#include <core/capability/Capability.h>

using namespace std;

class Capability;

class Device : public StateConnection {
private:
    string _name;
    long _id = -1;
    long _homeID = -1;
    long _roomID = -1;

    bool _initialized = false;

    vector<reference_wrapper<Capability>> _capabilities;

public:
    Device(vector<Capability &> &capabilities);

    ~Device() = default;

    virtual void init() = 0;

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
    vector<Capability &> getCapabilities();

    auto getCapByPin(const uint8_t &pin);

    void addCapability(Capability &cap);

    void removeCapability(long id);

    void removeCapabilityByPin(const uint8_t &pin);

    void initAllCapabilities();

    void executeAllCapabilities();

    void eraseAll();

    virtual unsigned long getDeviceMillis();
};

#endif  // DEVICE_H