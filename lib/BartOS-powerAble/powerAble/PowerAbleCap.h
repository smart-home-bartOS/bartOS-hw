//
// Created by mabartos on 4/12/21.
//

#ifndef BARTOS_HW_POWERABLECAP_H
#define BARTOS_HW_POWERABLECAP_H

#include <core/capability/Capability.h>

class PowerAbleCap : public Capability {
private:
    bool _isTurnedOn;
    bool _isInverseOutput = false;
protected:
    void setTurnedOn(bool state);

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

    bool isInverseOutput();

    void setInverseOutput(bool state);
};


#endif //BARTOS_HW_POWERABLECAP_H
