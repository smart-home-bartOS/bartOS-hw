#ifndef DEVICE_H
#define DEVICE_H

#include <memory>
#include <string>
#include <vector>
#include <StateConnection.h>
#include <capability/Capability.h>

using namespace std;

class Capability;

class Device : public StateConnection {
private:
    string _name;
    bool _initialized = false;
    vector<shared_ptr<Capability>> _capabilities;

    void changeCapAvailability(bool state);

protected:
    virtual void initAllCapabilities();

    virtual void executeAllCapabilities();

public:
    Device(const string &name);

    ~Device() = default;

    virtual void init();

    virtual void loop();

    string getName();

    void setName(const string &name);

    bool isInitialized();

    void setInitialized(bool initialized);

    void disableAllCapabilities();

    void enableAllCapabilities();

    /* CAPS */
    vector<shared_ptr<Capability>> getCapabilities();

    void setCapabilities(vector<shared_ptr<Capability>> &caps);

    shared_ptr<Capability> getCapByPinAndType(const uint8_t &pin, const string &type);

    void eraseAll();

    virtual unsigned long getDeviceMillis();
};

#endif  // DEVICE_H