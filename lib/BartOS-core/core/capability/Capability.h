#ifndef CAPABILITY_H
#define CAPABILITY_H

#include <cstdint>

#include "CapabilityFields.h"
#include "CapabilityType.h"
#include <string>
#include <memory>
#include "core/StateConnection.h"
#include <core/device/Device.h>
#include <core/callback/utils/CallbackType.h>
#include <core/callback/CallbackMap.h>
#include <core/callback/CallbackMapTime.h>
#include <iostream>
#include <unordered_map>

using namespace std;

class Capability : public StateConnection {
private:
    unsigned long _sampleTime = 0;
    unsigned long _lastExecution = 0;

    unsigned long _delayLastExecution = 0;
    unsigned long _delayTime = 0;

    bool isSampleTimeAchieved();

    bool isDelayTimeAchieved();

protected:
    long _ID = -1;
    uint8_t _pin;
    bool _enabled = true;
    string _name;
    string _type;

    shared_ptr<CallbackMap> _execCallbackMap;
    shared_ptr<CallbackMapTime> _loopCallbackMap;

    void delayExecution(unsigned long time);

public:
    Capability(const uint8_t &pin,
               const string &type = CapabilityType::OTHER,
               const string &name = "Cap-unknown",
               const unsigned sampleTime = 0);

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

    void setEnabled(bool enabled);

    void enable();

    void disable();

    unsigned long getSampleTime();

    void setSampleTime(unsigned millis);

    shared_ptr<CallbackMap> executeEventHandler();

    shared_ptr<CallbackMapTime> loopEventHandler();

    unsigned long getActualMillis();

    void printInfo();
};

#endif  // CAPABILITY_H