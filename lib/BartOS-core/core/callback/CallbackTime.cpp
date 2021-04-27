//
// Created by mabartos on 4/10/21.
//

#include "CallbackTime.h"
#include <Arduino.h>

CallbackTime::CallbackTime(uint32_t time, SimpleCallback callback, bool oneUseOnly) :
        _time(time), _callback(callback), _lastExec(getSystemTime()), _oneUseOnly(oneUseOnly) {
}

uint32_t CallbackTime::getTime() {
    return _time;
}

void CallbackTime::setTime(uint32_t time) {
    _time = time;
}

void CallbackTime::setCallback(SimpleCallback callback) {
    _callback = callback;
}

bool CallbackTime::isEnabled() {
    return _enabled;
}

void CallbackTime::setEnabled(bool state) {
    _enabled = state;
}

bool CallbackTime::isTimeAchieved() {
    if ((getSystemTime() - _lastExec) >= _time) {
        _lastExec = getSystemTime();
        return true;
    }
    return false;
}

bool CallbackTime::checkAndExecute() {
    if (isEnabled() && isTimeAchieved()) {
        _callback();
        return true;
    }
    return false;
}

bool CallbackTime::isOneUseOnly() {
    return _oneUseOnly;
}

uint32_t CallbackTime::getSystemTime() {
    return millis();
}