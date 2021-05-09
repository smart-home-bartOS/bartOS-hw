//
// Created by mabartos on 4/29/21.
//

#ifndef BARTOS_HW_MOTIONDATA_H
#define BARTOS_HW_MOTIONDATA_H

#include <transceiver/PubSubDataTransceiver.h>
#include <motion/MotionCap.h>

class MotionData : public PubSubDataTransceiver {
public:
    static const char *DETECTED;

    MotionData(shared_ptr<PubSubDataConnector> dataConnector);

    ~MotionData() = default;

    void sendData(MotionCap *cap);
};


#endif //BARTOS_HW_MOTIONDATA_H
