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
protected:
    string _name;
    bool _initialized = false;
    vector<shared_ptr<Capability>> _capabilities;

    virtual void initAllCapabilities();

    void printCapabilityInfo(const shared_ptr<Capability> &cap);

    virtual void executeAllCapabilities();

public:
    Device(vector<shared_ptr<Capability>> capabilities,
           const string &name = "Device",
           ConnectionType connectionType = ConnectionType::OFFLINE);

    ~Device() = default;

    virtual void init();

    virtual void loop();

    string getName();

    void setName(const string &name);

    bool isInitialized();

    void setInitialized(bool initialized);

    /* CAPS */
    vector<shared_ptr<Capability>> getCapabilities();

    void setCapabilities(vector<shared_ptr<Capability>> &caps);

    shared_ptr<Capability> getCapByPinAndType(const uint8_t &pin, const string &type);

    void eraseAll();

    virtual unsigned long getDeviceMillis();
};

#endif  // DEVICE_H