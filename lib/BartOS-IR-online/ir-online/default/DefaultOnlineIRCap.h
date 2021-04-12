//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_ONLINEINFRAREDCAP_H
#define BARTOS_HW_ONLINEINFRAREDCAP_H

#include <ir/default/DefaultIRCap.h>
#include <ir-online/InfraRedData.h>

class DefaultOnlineIRCap : public DefaultIRCap, public InfraRedData {

    DefaultOnlineIRCap(shared_ptr <PubSubDataConnector> dataConnector,
                       const uint8_t &pin,
                       const string &name = "Online_IR");

    ~DefaultOnlineIRCap() = default;

    void execute();

    void sendData() {
        InfraRedData::sendData(this);
    }
};


#endif //BARTOS_HW_ONLINEINFRAREDCAP_H
