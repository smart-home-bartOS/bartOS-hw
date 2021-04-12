//
// Created by mabartos on 4/15/21.
//

#ifndef BARTOS_HW_PUBSUBDATATRANSCEIVER_H
#define BARTOS_HW_PUBSUBDATATRANSCEIVER_H

#include "DataTransceiver.h"
#include <online-device/device/connector/PubSubDataConnector.h>
#include "PubSubCallbackMap.h"

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
};


#endif //BARTOS_HW_PUBSUBDATATRANSCEIVER_H
