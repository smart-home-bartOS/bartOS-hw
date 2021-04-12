//
// Created by mabartos on 4/11/21.
//

#include "DefaultIRCap.h"

DefaultIRCap::IrRemoteCap(const uint8_t &pin, const string &name) :
        InfraRedCap(pin, name) {
    _irRecv = make_shared<IRrecv>(pin);
    _results = make_shared<decode_results>();
}

void DefaultIRCap::init() {
    _irRecv->enableIRIn();
}

void DefaultIRCap::execute() {
    if (isSignalPresent()) {
        _value = _results->value;
        serialPrintUint64(_value, 16);
        _irRecv->resume();
    }
    yield();
}

bool DefaultIRCap::isSignalPresent() {
    return _irRecv->decode(_results.get());
}

// Get only once
uint32_t DefaultIRCap::getSignalValue() {
    const uint32_t tmp = _value;
    _value = 0;
    return tmp;
}

shared_ptr <decode_results> DefaultIRCap::getResults() {
    return _results;
}