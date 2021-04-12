//
// Created by mabartos on 4/11/21.
//

#ifndef BARTOS_HW_BUTTONCAP_H
#define BARTOS_HW_BUTTONCAP_H

#include <core/capability/Capability.h>

#define DEFAULT_DELAY_MILLIS 50

class ButtonCap : public Capability {
protected:
    bool _state;

    virtual void updateState() = 0;

public:
    ButtonCap(const uint8_t &pin, const string &name);

    ~ButtonCap() = default;

    bool isOn();

    bool isOff();

    virtual bool isChanged() = 0;
};

#endif //BARTOS_HW_BUTTONCAP_H
