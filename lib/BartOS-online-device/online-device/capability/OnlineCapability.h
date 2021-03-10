#ifndef ONLINE_CAPABILITY_H
#define ONLINE_CAPABILITY_H

#include <memory>

#include "core/capability/Capability.h"
#include "core/capability/CapabilityType.h"
#include "online-device/device/OnlineDevice.h"

using namespace std;

class OnlineCapability : public Capability {
   private:
    shared_ptr<OnlineDevice> _device;

   public:
    OnlineCapability(const uint8_t &pin, CapabilityType type);
    ~OnlineCapability() = default;

    virtual void reactToMessage(const JsonObject &obj);

    void publishValues(DynamicJsonDocument &data);

    string getTopic();

    void editCreateCapNested(JsonObject &nested);
};

#endif  //ONLINE_CAPABILITY_H