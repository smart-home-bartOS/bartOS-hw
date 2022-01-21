//
// Created by mabartos on 4/29/21.
//

#ifndef BARTOS_HW_DEFAULTMOTIONCAP_H
#define BARTOS_HW_DEFAULTMOTIONCAP_H

#include <MotionCap.h>

class DefaultMotionCap : public MotionCap {
   private:
    volatile bool _motionDetected = false;

   public:
    DefaultMotionCap(const uint8_t &pin);

    ~DefaultMotionCap() = default;

    void init() override;

    void loop() override;

    bool isMotionDetected() override;
};

#endif  // BARTOS_HW_DEFAULTMOTIONCAP_H
