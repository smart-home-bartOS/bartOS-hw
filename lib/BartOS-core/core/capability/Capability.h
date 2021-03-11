#ifndef CAPABILITY_H
#define CAPABILITY_H

#include <cstdint>

#include "CapabilityFields.h"
#include "CapabilityType.h"
#include "core/StateConnection.h"
#include "core/device/Device.h"

using namespace std;

class Capability : public StateConnection {
   private:
    long _ID = -1;
    uint8_t _pin;
    bool _enable;
    string _name = "";
    CapabilityType _type;
    shared_ptr<Device> _device;
    string _typeID = "";

    unsigned _sampleTime = 0;
    unsigned long _lastExecution;

   protected:
    bool isSampleTimeAchieved();

   public:
    Capability(const string &name, const uint8_t &pin, CapabilityType type);
    Capability(const string &name, const uint8_t &pin, CapabilityType type, const unsigned sampleTime);
    ~Capability() = default;

    virtual void init();
    void preExecute();
    virtual void execute();

    long getID();
    void setID(const long &id);

    virtual string getTypeID();
    virtual void setTypeID(const string &typeID);

    string getName();
    void setName(const string &name);

    uint8_t getPin();
    void setPin(const uint8_t &pin);

    CapabilityType getType();
    void setType(CapabilityType &type);

    bool isEnabled();

    unsigned getSampleTime();
    void setSampleTime(unsigned millis);

    shared_ptr<Device> getDevice();
    void setDevice(shared_ptr<Device> device);
};

#endif  // CAPABILITY_H