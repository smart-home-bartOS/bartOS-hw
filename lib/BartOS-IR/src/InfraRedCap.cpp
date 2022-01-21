//
// Created by mabartos on 4/11/21.
//

#include "InfraRedCap.h"

InfraRedCap::InfraRedCap(const uint8_t &pin,
                         bool printCodes) : Capability(pin, CapabilityType::INFRA_RED), _printCodes(printCodes) {
    _callbacks = make_shared<IrActionMap>();
    _onDecode = make_shared<ActionMap>();
}

shared_ptr<IrActionMap> InfraRedCap::codeHandler() {
    return _callbacks;
}

shared_ptr<ActionMap> InfraRedCap::onDecode() {
    return _onDecode;
}

bool InfraRedCap::shouldPrintCodes() {
    return _printCodes;
}

void InfraRedCap::setPrintCodes(bool state) {
    _printCodes = state;
}