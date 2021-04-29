//
// Created by mabartos on 4/29/21.
//

#ifndef BARTOS_HW_DEFAULTMOTIONCAP_H
#define BARTOS_HW_DEFAULTMOTIONCAP_H

#include <motion/MotionCap.h>

class DefaultMotionCap : public MotionCap {
private:
    bool _motionDetected = false;
public:
    DefaultMotionCap(const uint8_t &pin, const string &name = "Default-Motion-Cap");

    ~DefaultMotionCap() = default;

    void init() override;

    void execute() override;

    bool isMotionDetected() override;
};


#endif //BARTOS_HW_DEFAULTMOTIONCAP_H
