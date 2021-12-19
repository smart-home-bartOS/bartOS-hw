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

void ActionMap::executeAll() {
    for (auto item : getCallbacks()) {
        item.second->execute();
    }
}

void ActionMap::add(const std::string &name, Callback callback) {
    getCallbacks().insert({name, make_shared<AbstractCallbackItem>(callback)});
}