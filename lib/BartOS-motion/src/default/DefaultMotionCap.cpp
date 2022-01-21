//
// Created by mabartos on 4/29/21.
//

#include "default/DefaultMotionCap.h"

#include <Arduino.h>

DefaultMotionCap::DefaultMotionCap(const uint8_t &pin) : MotionCap(pin) {}

void DefaultMotionCap::init() {
    pinMode(getPin(), INPUT);
}

void DefaultMotionCap::loop() {
    _motionDetected = digitalRead(getPin());
}

bool DefaultMotionCap::isMotionDetected() {
    return _motionDetected;
}