#ifndef CAPABILITY_H
#define CAPABILITY_H

#include <cstdint>

#include "CapabilityFields.h"
#include "CapabilityType.h"
#include <string>
#include <memory>
#include <core/StateConnection.h>
#include <core/device/Device.h>

using namespace std;

class Device;

class Capability : public StateConnection {
private:
    long _ID = -1;
    uint8_t _pin;
    bool _enable = true;
    string _name = "";
    string _type = CapabilityType::OTHER;
    shared_ptr<Device> _device;

    unsigned _sampleTime = 0;
    unsigned long _lastExecution = 0;

protected:
    bool isSampleTimeAchieved();

public:
    Capability(const uint8_t &pin);

    Capability(const uint8_t &pin, const string &type);

    Capability(const uint8_t &pin, const string &type, const unsigned sampleTime);

    Capability(const uint8_t &pin, const string &type, const string &name);

    Capability(const uint8_t &pin, const string &type, const string &name, const unsigned sampleTime);

    ~Capability() = default;

    virtual void init();

    void preExecute();

    virtual void execute();

    long getID();

    void setID(const long &id);

    string getName();

    void setName(const string &name);

    uint8_t getPin();

    void setPin(const uint8_t &pin);

    string getType();

    void setType(const string &type);

    bool isEnabled();

    unsigned getSampleTime();

    void setSampleTime(unsigned millis);

    shared_ptr<Device> getDevice();

    void setDevice(shared_ptr<Device> device);
};

#endif  // CAPABILITY_H