//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_BUTTONDATA_H
#define BARTOS_HW_BUTTONDATA_H

#include <online-device/transceiver/PubSubDataTransceiver.h>
#include <button/ButtonCap.h>

class ButtonData : public PubSubDataTransceiver {
public:
    static const char *STATE;

    ButtonData(shared_ptr<PubSubDataConnector> dataConnector);

    ~ButtonData() = default;

    void sendData(ButtonCap *cap);
};


#endif //BARTOS_HW_BUTTONDATA_H
