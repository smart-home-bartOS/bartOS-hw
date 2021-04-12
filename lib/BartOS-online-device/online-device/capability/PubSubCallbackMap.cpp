//
// Created by mabartos on 4/19/21.
//

#include "PubSubCallbackMap.h"

void PubSubCallbackMap::handle(const string &topic, DynamicJsonDocument &doc) {
    auto it = _callbacks.find(topic);
    if (it != _callbacks.end()) {
        it->second(doc);
    }
}

void PubSubCallbackMap::clearAll() {
    _callbacks.clear();
}

void PubSubCallbackMap::add(const string &name, PubSubCallback callback) {
    _callbacks.insert({name, callback});
}

void PubSubCallbackMap::remove(const string &name) {
    _callbacks.erase(name);
}

uint32_t PubSubCallbackMap::getSize() {
    return _callbacks.size();
}