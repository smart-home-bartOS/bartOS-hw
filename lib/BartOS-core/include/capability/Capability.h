#ifndef CAPABILITY_H
#define CAPABILITY_H

#include <callback/ActionMap.h>
#include <callback/TimeActionMap.h>
#include <callback/utils/CallbackType.h>
#include <device/Device.h>

#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

#include "CapabilityFields.h"
#include "CapabilityType.h"

using std::make_shared;
using std::shared_ptr;
using std::string;
using std::unordered_map;

class Capability {
   private:
    shared_ptr<ActionMap> _actions;
    shared_ptr<TimeActionMap> _scheduler;

    unsigned long _sampleTime = 0;
    unsigned long _lastExecution = 0;

    unsigned long _delayLastExecution = 0;
    unsigned long _delayTime = 0;

    bool isSampleTimeAchieved();
    bool isDelayTimeAchieved();

   protected:
    uint8_t _pin;
    bool _enabled = true;
    string _name;
    string _type;

    void delayExecution(unsigned long time);
    unsigned long getActualMillis();

    unsigned long getSampleTime();
    void setSampleTime(unsigned millis);

   public:
    Capability(const uint8_t &pin,
               const string &type = CapabilityType::OTHER,
               const string &name = "Cap-unknown",
               const unsigned sampleTime = 0);

    ~Capability() = default;

    virtual void init();
    virtual void loop();

    void priorLoop();

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

    shared_ptr<ActionMap> actions();

    shared_ptr<TimeActionMap> scheduler();

    void printInfo();
};

#endif  // CAPABILITY_H