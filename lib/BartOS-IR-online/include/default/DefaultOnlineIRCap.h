//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_ONLINEINFRAREDCAP_H
#define BARTOS_HW_ONLINEINFRAREDCAP_H

#include <default/DefaultIRCap.h>

#include "InfraRedOnline.h"

class DefaultOnlineIRCap : public DefaultIRCap, public InfraRedOnline {
   public:
    DefaultOnlineIRCap(const uint8_t &pin,
                       const string &name = "Online_IR");

    ~DefaultOnlineIRCap() = default;

    void loop();
};

#endif  // BARTOS_HW_ONLINEINFRAREDCAP_H
