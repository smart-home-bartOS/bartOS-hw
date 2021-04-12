//
// Created by mabartos on 4/10/21.
//

#include "CallbackMapTime.h"

CallbackMapTime::CallbackMapTime() : CallbackMap() {
}

void CallbackMapTime::executeAll() {
    CallbackMap::executeAll();

    for (auto item:_timeCallbacks) {
        item.second->checkAndExecute();
    }
}

void CallbackMapTime::period(const string &name, uint32_t time, SimpleCallback callback) {
    shared_ptr<CallbackTime> callbackTime = make_shared<CallbackTime>(time, callback);
    _timeCallbacks.insert({name, callbackTime});
}

void CallbackMapTime::changePeriodTime(const string &name, uint32_t time) {
    auto it = _timeCallbacks.find(name);
    if (it != _timeCallbacks.end()) {
        it->second->setTime(time);
    }
}

void CallbackMapTime::changeEnableState(const string &name, bool state) {
    auto it = _timeCallbacks.find(name);
    if (it != _timeCallbacks.end()) {
        it->second->setEnabled(state);
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

uint32_t CallbackMapTime::getSize() {
    return CallbackMap::getSize() + _timeCallbacks.size();
}

