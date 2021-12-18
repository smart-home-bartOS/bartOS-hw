//
// Created by mabartos on 3/31/21.
//

#include "callback/ActionMap.h"
using std::make_shared;

void ActionMap::execute(const std::string &name) {
    auto it = getCallbacks().find(name);
    if (it != getCallbacks().end()) {
        it->second->execute();
    }
}

void ActionMap::loop() {
    for (auto item : getCallbacks()) {
        item.second->execute();
    }
}

void ActionMap::add(const std::string &name, Callback callback) {
    getCallbacks().insert({name, make_shared<AbstractCallbackItem>(callback)});
}

/*void ActionMap::changeEnableState(const std::string &name, bool state) {
    auto it = _callbacks.find(name);
    if (it != _callbacks.end()) {
        it->second->setEnabled(state);
    }
}

void ActionMap::enable(const std::string &name) {
    changeEnableState(name, true);
};

void ActionMap::disable(const std::string &name) {
    changeEnableState(name, false);
};

void ActionMap::remove(const std::string &name) {
    _callbacks.erase(name);
};

void ActionMap::removeAll() {
    _callbacks.clear();
};

uint32_t ActionMap::getSize() {
    return _callbacks.size();
};

bool ActionMap::existsCallback(const std::string &name) {
    if (name.empty()) return false;
    auto it = _callbacks.find(name);
    return it != _callbacks.end();
};*/