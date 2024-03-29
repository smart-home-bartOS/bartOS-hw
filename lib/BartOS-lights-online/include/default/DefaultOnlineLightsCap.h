//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_DEFAULTONLINELIGHTSCAP_H
#define BARTOS_HW_DEFAULTONLINELIGHTSCAP_H

#include <default/DefaultLightsCap.h>

#include "LightsOnline.h"

class DefaultOnlineLightsCap : public DefaultLightsCap, public LightsOnline {
   public:
    DefaultOnlineLightsCap(const uint8_t &pin,
                           uint32_t pwmRange = DEFAULT_PWM_RANGE);

    ~DefaultOnlineLightsCap() = default;
};

#endif  // BARTOS_HW_DEFAULTONLINELIGHTSCAP_H
