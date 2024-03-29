//
// Created by mabartos on 4/11/21.
//

#ifndef BARTOS_HW_TWOWAYBUTTON_H
#define BARTOS_HW_TWOWAYBUTTON_H

#include <string>

#include "ButtonCap.h"
using std::string;

class TwoWayButton : public ButtonCap {
   protected:
    void updateState();

   public:
    TwoWayButton(const uint8_t &pin);

    ~TwoWayButton() = default;

    void init();

    bool isOn();

    bool isOff();
};

#endif  // BARTOS_HW_TWOWAYBUTTON_H
