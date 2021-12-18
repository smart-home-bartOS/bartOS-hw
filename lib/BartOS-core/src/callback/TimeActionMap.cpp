//
// Created by mabartos on 4/10/21.
//

#include "callback/TimeActionMap.h"

#include <Arduino.h>
using std::make_shared;

void TimeActionMap::loop() {
    for (auto item : getCallbacks()) {
        item.second->execute();

        if (item.second->isOneUseOnly()) {
            item.second.reset();
            getCallbacks().erase(item.first);
        }
    }
}

void TimeActionMap::timer(const std::string &name, uint32_t time, Callback callback) {
    if (existsCallback(name)) return;
    getCallbacks().insert({name, make_shared<CallbackTime>(time, callback, true)});
}

void TimeActionMap::period(const std::string &name, uint32_t time, Callback callback) {
    if (existsCallback(name)) return;
    getCallbacks().insert({name, make_shared<CallbackTime>(time, callback)});
}

void TimeActionMap::update(const std::string &name, uint32_t time, Callback callback) {
    auto it = getCallbacks().find(name);
    if (it != getCallbacks().end()) {
        it->second->setTime(time);
        it->second->setCallback(callback);
    }
}
