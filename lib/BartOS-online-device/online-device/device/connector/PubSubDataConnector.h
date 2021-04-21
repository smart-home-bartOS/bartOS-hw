//
// Created by mabartos on 4/15/21.
//

#ifndef BARTOS_HW_PUBSUBDATACONNECTOR_H
#define BARTOS_HW_PUBSUBDATACONNECTOR_H

#include "DataConnector.h"
#include <unordered_map>
#include <string>
#include <stdint.h>
#include "online-device/utils/OnlineCallbackUtils.h"

using namespace std;

class PubSubDataConnector : public DataConnector {
private:
    unordered_map<string, PubSubCallback> _topicCallbacks;
protected:
    void executeTopicContext(char *topic, DynamicJsonDocument doc);

public:
    explicit PubSubDataConnector() = default;

    ~PubSubDataConnector() = default;

    unordered_map<string, PubSubCallback> getTopicContext();

    virtual void addTopicContext(const string &topic, PubSubCallback callback);

    virtual void removeTopicContext(const string &topic);

    void clearAllTopicContexts();
};


#endif //BARTOS_HW_PUBSUBDATACONNECTOR_H
