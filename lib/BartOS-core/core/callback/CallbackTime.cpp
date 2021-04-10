//
// Created by mabartos on 4/10/21.
//

#include "CallbackTime.h"
#include <Arduino.h>

CallbackTime::CallbackTime(uint32_t time, Callback callback) :
        _time(time), _callback(callback) {}

uint32_t CallbackTime::getTime() {
    return _time;
}

void CallbackTime::setTime(uint32_t time) {
    _time = time;
    setNewResultExecuteTime(time);
}

void CallbackTime::setCallback(Callback callback) {
    _callback = callback;
}

bool CallbackTime::isEnabled() {
    return _enabled;
}

void CallbackTime::setEnabled(bool state) {
    _enabled = state;
}

void CallbackTime::checkAndExecute(unsigned long systemTime) {
    Serial.println("CHECK AND EXEC");
    if (isEnabled() && systemTime >= _resultMillis) {
        Serial.println("HERE1");
        _callback();
        Serial.println("HERE2");

        setNewResultExecuteTime(systemTime);
    }
}

unsigned long CallbackTime::getSystemTime() {
    return millis();
}

void CallbackTime::setNewResultExecuteTime(unsigned long systemTime) {
    _resultMillis = systemTime + _time;
}

void CallbackTime::setNewResultExecuteTime(uint32_t time) {
    _resultMillis = getSystemTime() + time;
}