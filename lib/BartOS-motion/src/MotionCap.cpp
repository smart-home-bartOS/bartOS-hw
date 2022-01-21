//
// Created by mabartos on 4/29/21.
//

#include "MotionCap.h"

MotionCap::MotionCap(const uint8_t &pin,
                     const unsigned sampleTime) : Capability(pin, CapabilityType::PIR, sampleTime) {
}