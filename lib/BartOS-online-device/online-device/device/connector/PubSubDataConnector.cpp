//
// Created by mabartos on 4/15/21.
//

#include "PubSubDataConnector.h"

void PubSubDataConnector::executeTopicContext(char *topic, JsonObject &doc) {
    if (strlen(topic) == 0) return;

    auto it = _topicCallbacks.find(topic);
    if (it != _topicCallbacks.end()) {
        it->second(doc);
    }
}

unordered_map<string, PubSubCallback> PubSubDataConnector::getTopicContext() {
    return _topicCallbacks;
}

void PubSubDataConnector::addTopicContext(const string &topic, PubSubCallback callback) {
    if (topic.empty()) return;

    _topicCallbacks.insert({topic, callback});
}

void PubSubDataConnector::removeTopicContext(const string &topic) {
    if (topic.empty()) return;

    _topicCallbacks.erase(topic);
}

void PubSubDataConnector::clearAllTopicContexts() {
    _topicCallbacks.clear();
}