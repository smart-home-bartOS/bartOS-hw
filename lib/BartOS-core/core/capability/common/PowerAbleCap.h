//
// Created by mabartos on 4/12/21.
//

#ifndef BARTOS_HW_POWERABLECAP_H
#define BARTOS_HW_POWERABLECAP_H

#include <core/capability/Capability.h>

class PowerAbleCap : public Capability {
protected:
    bool _isTurnedOn;
public:
    PowerAbleCap(const uint8_t &pin,
                 const string &type = CapabilityType::OTHER,
                 const string &name = "PowerAbleCap");

    ~PowerAbleCap() = default;

    virtual void turnOn() = 0;

    virtual void turnOff() = 0;

    virtual bool isTurnedOn();

    virtual void changeState(bool state);

    virtual void switchState();
};


#endif //BARTOS_HW_POWERABLECAP_H
