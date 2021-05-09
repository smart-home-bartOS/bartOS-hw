//
// Created by mabartos on 4/11/21.
//

#include "InfraRedCap.h"

InfraRedCap::InfraRedCap(const uint8_t &pin, const string &name, bool printCodes) :
        Capability(pin, CapabilityType::INFRA_RED, name), _printCodes(printCodes) {
    _callbacks = make_shared<IrCallbackMap>();
}

shared_ptr<IrCallbackMap> InfraRedCap::callbacks() {
    return _callbacks;
}

bool InfraRedCap::shouldPrintCodes() {
    return _printCodes;
}

void InfraRedCap::setPrintCodes(bool state) {
    _printCodes = state;
}