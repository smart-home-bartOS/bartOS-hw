//
// Created by mabartos on 4/13/21.
//

#ifndef BARTOS_HW_DEFAULTPOWERCAP_H
#define BARTOS_HW_DEFAULTPOWERCAP_H

#include <powerAble/PowerAbleCap.h>

class DefaultPowerCap : public PowerAbleCap {
public:
    DefaultPowerCap(const uint8_t &pin, const string &name = "DefaultPowerAble");

    ~DefaultPowerCap() = default;

    void init();

    void turnOn();

    void turnOff();
};


#endif //BARTOS_HW_DEFAULTPOWERCAP_H
