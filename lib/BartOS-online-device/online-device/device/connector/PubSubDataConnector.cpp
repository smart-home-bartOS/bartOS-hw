//
// Created by mabartos on 4/15/21.
//

#include "PubSubDataConnector.h"

void PubSubDataConnector::handleData(const char *topic,const char *payload, unsigned int length) {
    StaticJsonDocument<MESSAGE_SIZE> doc;
    DeserializationError err = deserializeJson(doc, payload, length);
    if (err) {
        Serial.println(err.c_str());
        return;
    }
    JsonObject obj = doc.as<JsonObject>();
    executeTopicContext(topic, obj);
}

void PubSubDataConnector::executeTopicContext(const char *topic, JsonObject &doc) {
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