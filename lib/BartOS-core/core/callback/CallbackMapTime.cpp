//
// Created by mabartos on 4/10/21.
//

#include "CallbackMapTime.h"
#include <Arduino.h>

CallbackMapTime::CallbackMapTime() : CallbackMap() {
}

void CallbackMapTime::executeAll() {
    CallbackMap::executeAll();
    unsigned long now = getSystemTime();

    for (auto item:_timeCallbacks) {
        item.second.checkAndExecute(now);
    }
}

void CallbackMapTime::period(const string &name, uint32_t time, Callback callback) {
    CallbackTime callbackTime(time, callback);
    _timeCallbacks.insert({name, callbackTime});
}

void CallbackMapTime::changePeriodTime(const string &name, uint32_t time) {
    auto it = _timeCallbacks.find(name);
    if (it != _timeCallbacks.end()) {
        it->second.setTime(time);
    }
}

void CallbackMapTime::changeEnableState(const string &name, bool state) {
    auto it = _timeCallbacks.find(name);
    if (it != _timeCallbacks.end()) {
        it->second.setEnabled(state);
    }
}

void CallbackMapTime::stopPeriod(const string &name) {
    changeEnableState(name, false);
}

void CallbackMapTime::resumePeriod(const string &name) {
    changeEnableState(name, true);
}

void CallbackMapTime::removePeriod(const string &name) {
    _timeCallbacks.erase(name);
}

unsigned long CallbackMapTime::getSystemTime() {
    return millis();
}

uint32_t CallbackMapTime::getSize() {
    return CallbackMap::getSize() + _timeCallbacks.size();
}

