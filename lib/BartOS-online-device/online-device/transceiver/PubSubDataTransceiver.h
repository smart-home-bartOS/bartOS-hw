//
// Created by mabartos on 4/15/21.
//

#ifndef BARTOS_HW_PUBSUBDATATRANSCEIVER_H
#define BARTOS_HW_PUBSUBDATATRANSCEIVER_H

#include "DataTransceiver.h"
#include <online-device/device/connector/PubSubDataConnector.h>
#include <online-device/utils/PubSubTopics.h>

class PubSubDataTransceiver : public DataTransceiver<PubSubDataConnector> {
public:
    PubSubDataTransceiver(shared_ptr<PubSubDataConnector> connector) :
            DataTransceiver<PubSubDataConnector>(connector) {};

    ~PubSubDataTransceiver() = default;

    /**
     * Add Data handler callback for default topics
     *
     * f.e
     * /cap/temp/myOwnTemp
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

        Serial.printf("Add callback to topics for capability '%s' with type '%s':\n",
                      cap->getName().c_str(),
                      cap->getType().c_str());

        getDataConnector()->addTopicContext(PubSubTopics::getCapabilityNameTopic(cap), callback);
        Serial.printf("Topic '%s'\n", PubSubTopics::getCapabilityNameTopic(cap).c_str());
        Serial.println(getDataConnector()->getTopicContext().size());
        if (deviceID != -1) {
            getDataConnector()->addTopicContext(PubSubTopics::getCapabilityDeviceTopic(deviceID, cap), callback);
            Serial.printf("Topic '%s'\n", PubSubTopics::getCapabilityDeviceTopic(deviceID, cap).c_str());
        }

        if (homeID != -1) {
            getDataConnector()->addTopicContext(PubSubTopics::getCapabilityHomeTopic(homeID, cap), callback);
            Serial.printf("Topic '%s'\n", PubSubTopics::getCapabilityHomeTopic(homeID, cap).c_str());
            if (roomID != -1) {
                getDataConnector()->addTopicContext(PubSubTopics::getCapabilityHomeRoomTopic(homeID, roomID, cap),
                                                    callback);
                Serial.printf("Topic '%s'\n", PubSubTopics::getCapabilityHomeRoomTopic(homeID, roomID, cap).c_str());
            }
            if (deviceID != -1) {
                getDataConnector()->addTopicContext(
                        PubSubTopics::getCapabilityRoomDeviceTopic(homeID, roomID, deviceID, cap),
                        callback);
                Serial.printf("Topic '%s'\n",
                              PubSubTopics::getCapabilityRoomDeviceTopic(homeID, roomID, deviceID, cap).c_str());
            }
        }
    }
};


#endif //BARTOS_HW_PUBSUBDATATRANSCEIVER_H
