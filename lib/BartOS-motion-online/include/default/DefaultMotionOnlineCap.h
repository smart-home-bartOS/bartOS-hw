//
// Created by mabartos on 4/29/21.
//

#ifndef BARTOS_HW_DEFAULTMOTIONONLINECAP_H
#define BARTOS_HW_DEFAULTMOTIONONLINECAP_H

#include <default/DefaultMotionCap.h>
#include "MotionData.h"

class DefaultMotionOnlineCap : public DefaultMotionCap, public MotionData {
public:
    DefaultMotionOnlineCap(shared_ptr <PubSubDataConnector> dataConnector,
                           const uint8_t &pin,
                           const string &name = "Online-Def-Motion-Cap");

    ~DefaultMotionOnlineCap() = default;
    
    void execute() override;

    void sendData();
};


#endif //BARTOS_HW_DEFAULTMOTIONONLINECAP_H
