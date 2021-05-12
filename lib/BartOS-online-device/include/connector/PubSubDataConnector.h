//
// Created by mabartos on 4/15/21.
//

#ifndef BARTOS_HW_PUBSUBDATACONNECTOR_H
#define BARTOS_HW_PUBSUBDATACONNECTOR_H

#include "DataConnector.h"
#include <unordered_map>
#include <string>
#include <stdint.h>
#include <utils/OnlineCallbackUtils.h>

#define MESSAGE_SIZE 200
using namespace std;

class PubSubDataConnector : public DataConnector {
private:
    unordered_map<string, PubSubCallback> _topicCallbacks;
protected:
    void executeTopicContext(const char *topic, JsonObject &doc);

public:
    explicit PubSubDataConnector() = default;

    ~PubSubDataConnector() = default;

    void handleData(const char *topic, const char *payload, unsigned int length);

    unordered_map<string, PubSubCallback> getTopicContext();

    virtual void addTopicContext(const string &topic, PubSubCallback callback);

    virtual void removeTopicContext(const string &topic);

    void clearAllTopicContexts();
};


#endif //BARTOS_HW_PUBSUBDATACONNECTOR_H
