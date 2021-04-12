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
    bool _initialized = false;
    vector<shared_ptr<Capability>> _capabilities;

    void printCapabilityInfo(const shared_ptr<Capability> &cap);

public:
    Device(vector<shared_ptr<Capability>> capabilities,
           const string &name = "Device",
           ConnectionType connectionType = ConnectionType::OFFLINE);

    ~Device() = default;

    virtual void init();

    string getName();

    void setName(const string &name);

    bool isInitialized();

    void setInitialized(bool initialized);

    /* CAPS */
    vector<shared_ptr<Capability>> getCapabilities();

    void setCapabilities(vector<shared_ptr<Capability>> &caps);

    auto getCapByPin(const uint8_t &pin) -> shared_ptr<Capability>;

    void initAllCapabilities();

    void executeAllCapabilities();

    void eraseAll();

    virtual unsigned long getDeviceMillis();
};

#endif  // DEVICE_H