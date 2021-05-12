//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_IRONLINEREMOTECAP_H
#define BARTOS_HW_IRONLINEREMOTECAP_H

#include <transceiver/PubSubDataTransceiver.h>
#include <InfraRedCap.h>

class InfraRedData : public PubSubDataTransceiver {
public:
    static const char *VALUE;

    InfraRedData(shared_ptr<PubSubDataConnector> dataConnector);

    ~InfraRedData() = default;

    void sendData(InfraRedCap *cap);
};


#endif //BARTOS_HW_IRONLINEREMOTECAP_H
