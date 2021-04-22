//
// Created by mabartos on 4/15/21.
//

#include "PubSubDataConnector.h"

void PubSubDataConnector::executeTopicContext(char *topic, JsonObject &doc) {
    auto it = _topicCallbacks.find(topic);
    if (it != _topicCallbacks.end()) {
        it->second(doc);
    }
}

unordered_map<string, PubSubCallback> PubSubDataConnector::getTopicContext() {
    return _topicCallbacks;
}

void PubSubDataConnector::addTopicContext(const string &topic, PubSubCallback callback) {
    _topicCallbacks.insert({topic, callback});
}

void PubSubDataConnector::removeTopicContext(const string &topic) {
    _topicCallbacks.erase(topic);
}

void PubSubDataConnector::clearAllTopicContexts() {
    _topicCallbacks.clear();
}