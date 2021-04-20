//
// Created by mabartos on 4/15/21.
//

#ifndef BARTOS_HW_PUBSUBDATATRANSCEIVER_H
#define BARTOS_HW_PUBSUBDATATRANSCEIVER_H

#include "DataTransceiver.h"
#include <online-device/device/connector/PubSubDataConnector.h>
#include "PubSubCallbackMap.h"
#include <online-device/utils/PubSubTopics.h>

class PubSubDataTransceiver : public DataTransceiver<PubSubDataConnector> {
private:
    shared_ptr<PubSubCallbackMap> _topicCallbackMap;
public:
    PubSubDataTransceiver(shared_ptr<PubSubDataConnector> connector) : DataTransceiver<PubSubDataConnector>(connector) {
    };

    ~PubSubDataTransceiver() = default;

    shared_ptr<PubSubCallbackMap> topicCallbacks() {
        return _topicCallbackMap;
    }

    void setTopicCallbacks(shared_ptr<PubSubCallbackMap> callbacks) {
        _topicCallbackMap = callbacks;
    }

    /**
     * Add Data handler callback for default topics
     *
     * f.e
     * /devices/8/temp/4
     * /homes/2/temp/4
     * /homes/2/rooms/16/temp/4
     * /homes/2/devices/8/temp/4
     * /homes/2/rooms/16/devices/8/temp/4
     */
    void addSameCallbackForBasicTopics(Capability *cap,
                                       PubSubCallback callback,
                                       long deviceID = -1,
                                       long homeID = -1,
                                       long roomID = -1) {
        if (cap == nullptr) return;

        if (deviceID != -1) {
            topicCallbacks()->add(PubSubTopics::getCapabilityDeviceTopic(deviceID, cap), callback);
        }

        if (homeID != -1) {
            topicCallbacks()->add(PubSubTopics::getCapabilityHomeTopic(homeID, cap), callback);
            if (roomID != -1) {
                topicCallbacks()->add(PubSubTopics::getCapabilityHomeRoomTopic(homeID, roomID, cap), callback);
            }
            if (deviceID != -1) {
                topicCallbacks()->add(PubSubTopics::getCapabilityRoomDeviceTopic(homeID, roomID, deviceID, cap),
                                      callback);
            }
        }
    }
};


#endif //BARTOS_HW_PUBSUBDATATRANSCEIVER_H
