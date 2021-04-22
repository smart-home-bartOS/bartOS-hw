//
// Created by mabartos on 4/19/21.
//

#include "PubSubCallbackMap.h"

void PubSubCallbackMap::handle(const string &topic, JsonObject &doc) {
    if (topic.empty()) return;

    auto it = _callbacks.find(topic);
    if (it != _callbacks.end()) {
        it->second(doc);
    }
}

void PubSubCallbackMap::clearAll() {
    _callbacks.clear();
}

void PubSubCallbackMap::add(const string &name, PubSubCallback callback) {
    if (name.empty()) return;
    _callbacks.insert({name, callback});
}

void PubSubCallbackMap::remove(const string &name) {
    if (name.empty()) return;
    _callbacks.erase(name);
}

uint32_t PubSubCallbackMap::getSize() {
    return _callbacks.size();
}