//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_POWERABLEDATA_H
#define BARTOS_HW_POWERABLEDATA_H

#include <online-device/capability/PubSubDataTransceiver.h>
#include <powerAble/PowerAbleCap.h>

class PowerAbleData : public PubSubDataTransceiver {
public:
    static const char *STATE;

    PowerAbleData(shared_ptr<PubSubDataConnector> dataConnector);

    ~PowerAbleData() = default;

    void sendData(PowerAbleCap *cap);
};


#endif //BARTOS_HW_POWERABLEDATA_H
