//
// Created by mabartos on 4/29/21.
//

#ifndef BARTOS_HW_MOTIONCAP_H
#define BARTOS_HW_MOTIONCAP_H

#include <core/capability/Capability.h>

#define DEFAULT_SAMPLE_TIME 500

class MotionCap : public Capability {
public:
    MotionCap(const uint8_t &pin,
              const string &name = "Motion-Cap",
              const unsigned sampleTime = DEFAULT_SAMPLE_TIME);

    ~MotionCap() = default;

    virtual bool isMotionDetected() = 0;
};


#endif //BARTOS_HW_MOTIONCAP_H
