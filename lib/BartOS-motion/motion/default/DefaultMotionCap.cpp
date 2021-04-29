//
// Created by mabartos on 4/29/21.
//

#include "DefaultMotionCap.h"
#include <Arduino.h>

DefaultMotionCap::DefaultMotionCap(const uint8_t &pin, const string &name) :
        MotionCap(pin, name) {}

void DefaultMotionCap::init() {
    pinMode(getPin(), INPUT);
}

void DefaultMotionCap::execute() {
    _motionDetected = digitalRead(getPin());
}

bool DefaultMotionCap::isMotionDetected() {
    return _motionDetected;
}