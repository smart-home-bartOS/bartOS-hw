//
// Created by mabartos on 4/11/21.
//

#include "InfraRedCap.h"

InfraRedCap::InfraRedCap(const uint8_t &pin, const string &name) :
        Capability(pin, CapabilityType::INFRA_RED, name) {
}

uint32_t InfraRedCap::getSignalValue() {
    return _value;
}