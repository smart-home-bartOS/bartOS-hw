//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_DEFAULTONLINEPOWERCAP_H
#define BARTOS_HW_DEFAULTONLINEPOWERCAP_H

#include <default/DefaultPowerCap.h>

#include "PowerAbleOnline.h"

class DefaultOnlinePowerCap : public DefaultPowerCap, public PowerAbleOnline {
   public:
    DefaultOnlinePowerCap(const uint8_t &pin,
                          const string &name = "DefaultOnlinePowerAble");

    ~DefaultOnlinePowerCap() = default;

    void init() override;

    void loop() override;
};

#endif  // BARTOS_HW_DEFAULTONLINEPOWERCAP_H
