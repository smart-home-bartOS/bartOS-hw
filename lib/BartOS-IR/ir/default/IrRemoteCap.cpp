//
// Created by mabartos on 4/11/21.
//

#include "IrRemoteCap.h"

IrRemoteCap::IrRemoteCap(const uint8_t &pin, const string &name) : InfraRedCap(pin, name) {
    _irRecv = make_shared<IRrecv>(pin);
    _results = make_shared<decode_results>();
}

void IrRemoteCap::init() {
    _irRecv->enableIRIn();
}

void IrRemoteCap::execute() {
    if (isSignalPresent()) {
        _value = _results->value;
        serialPrintUint64(_value, 16);
        _irRecv->resume();
    }
    yield();
}

bool IrRemoteCap::isSignalPresent() {
    return _irRecv->decode(_results.get());
}

// Get only once
uint32_t IrRemoteCap::getSignalValue() {
    const uint32_t tmp = _value;
    _value = 0;
    return tmp;
}

shared_ptr <decode_results> IrRemoteCap::getResults() {
    return _results;
}