//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_DEFAULTONLINEPOWERCAP_H
#define BARTOS_HW_DEFAULTONLINEPOWERCAP_H

#include <powerAble/default/DefaultPowerCap.h>
#include <powerAble-online/PowerAbleData.h>

class DefaultOnlinePowerCap : public DefaultPowerCap, public PowerAbleData {
public:
    DefaultOnlinePowerCap(shared_ptr <PubSubDataConnector> dataConnector,
                          const uint8_t &pin,
                          const string &name = "DefaultOnlinePowerAble");

    ~DefaultOnlinePowerCap() = default;

    void execute();

    void sendData() {
        PowerAbleData::sendData(this);
    }
};


#endif //BARTOS_HW_DEFAULTONLINEPOWERCAP_H