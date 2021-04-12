//
// Created by mabartos on 4/11/21.
//

#ifndef BARTOS_HW_INFRARED_CAP_H
#define BARTOS_HW_INFRARED_CAP_H

using namespace std;

#include <string>
#include <stdint.h>
#include <core/capability/Capability.h>

class InfraRedCap : public Capability {
protected:
    uint32_t _value;
public:
    InfraRedCap(const uint8_t &pin, const string &name);

    ~InfraRedCap() = default;

    virtual bool isSignalPresent() = 0;

    uint32_t getSignalValue();
};


#endif //BARTOS_HW_INFRARED_CAP_H
