#ifndef DEVICE_H
#define DEVICE_H

#include <capability/Capability.h>

#include <memory>
#include <string>
#include <vector>

using std::shared_ptr;
using std::string;
using std::vector;

class Capability;

class Device {
   private:
    vector<shared_ptr<Capability>> _capabilities;
    shared_ptr<TimeActionMap> _scheduler;

   protected:
    virtual void initCapabilities();
    virtual void loopCapabilities();
    virtual unsigned long getDeviceMillis();
    void changeCapabilityState(bool state);

   public:
    Device();
    ~Device() = default;

    virtual void init();

    virtual void loop();

    void disableCapabilities();

    void enableCapabilities();

    /* CAPS */
    vector<shared_ptr<Capability>> getCapabilities();

    void setCapabilities(vector<shared_ptr<Capability>> &caps);

    shared_ptr<Capability> getCapByPinAndType(const uint8_t &pin, const string &type);

    void factoryReset();

    shared_ptr<TimeActionMap> scheduler();
};

#endif  // DEVICE_H