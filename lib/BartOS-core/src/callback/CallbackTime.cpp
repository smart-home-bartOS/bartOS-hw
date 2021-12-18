//
// Created by mabartos on 4/10/21.
//

#include "callback/CallbackTime.h"

#include <Arduino.h>

CallbackTime::CallbackTime(uint32_t time,
                           Callback callback,
                           bool oneUseOnly) : AbstractCallbackItem(callback),
                                              _time(time),
                                              _lastExec(getSystemTime()),
                                              _oneUseOnly(oneUseOnly) {
}

uint32_t CallbackTime::getTime() {
    return _time;
}

void CallbackTime::setTime(uint32_t time) {
    _time = time;
}

bool CallbackTime::isTimeAchieved() {
    if ((getSystemTime() - _lastExec) >= _time) {
        _lastExec = getSystemTime();
        return true;
    }
    return false;
}

void CallbackTime::execute() {
    if (isEnabled() && isTimeAchieved()) {
        AbstractCallbackItem::execute();
    }
}

bool CallbackTime::isOneUseOnly() {
    return _oneUseOnly;
}

uint32_t CallbackTime::getSystemTime() {
    return millis();
}