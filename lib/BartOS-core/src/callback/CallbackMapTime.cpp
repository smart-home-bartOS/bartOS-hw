//
// Created by mabartos on 4/10/21.
//

#include "callback/CallbackMapTime.h"
#include <Arduino.h>

CallbackMapTime::CallbackMapTime() : CallbackMap() {
}

void CallbackMapTime::executeAll() {
    CallbackMap::executeAll();

    for (auto item:_timeCallbacks) {
        if (item.second->checkAndExecute() && item.second->isOneUseOnly()) {
            item.second.reset();
            _timeCallbacks.erase(item.first);
        }
    }
}

void CallbackMapTime::timer(const string &name, uint32_t time, SimpleCallback callback) {
    if (existsCallback(name)) return;
    _timeCallbacks.insert({name, make_shared<CallbackTime>(time, callback, true)});
}

void CallbackMapTime::period(const string &name, uint32_t time, SimpleCallback callback) {
    if (existsCallback(name)) return;
    _timeCallbacks.insert({name, make_shared<CallbackTime>(time, callback)});
}

void CallbackMapTime::update(const string &name, uint32_t time, SimpleCallback callback) {
    auto it = _timeCallbacks.find(name);
    if (it != _timeCallbacks.end()) {
        it->second->setTime(time);
        it->second->setCallback(callback);
    }
}

void CallbackMapTime::changeEnableState(const string &name, bool state) {
    auto it = _timeCallbacks.find(name);
    if (it != _timeCallbacks.end()) {
        it->second->setEnabled(state);
    }
}

void CallbackMapTime::enable(const string &name) {
    changeEnableState(name, true);
}

void CallbackMapTime::disable(const string &name) {
    changeEnableState(name, false);
}

uint32_t CallbackMapTime::getSize() {
    return CallbackMap::getSize() + _timeCallbacks.size();
}

bool CallbackMapTime::existsCallback(const string &name) {
    bool existsSimple = CallbackMap::existsCallback(name);

    if (name.empty()) return false;
    auto it = _timeCallbacks.find(name);
    bool exists = it != _timeCallbacks.end();

    return existsSimple && exists;
}

