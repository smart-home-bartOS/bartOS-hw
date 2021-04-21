//
// Created by mabartos on 4/21/21.
//

#ifndef BARTOS_HW_ONLINECAPABILITY_H
#define BARTOS_HW_ONLINECAPABILITY_H

#include <core/capability/Capability.h>

class OnlineCapability : public Capability {
public:
    OnlineCapability(const uint8_t &pin,
                     const string &type = CapabilityType::OTHER,
                     const string &name = "Online-Cap-unknown",
                     const unsigned sampleTime = 0);

    ~OnlineCapability() = default;
};


#endif //BARTOS_HW_ONLINECAPABILITY_H
