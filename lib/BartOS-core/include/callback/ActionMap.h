//
// Created by mabartos on 3/31/21.
//

#ifndef BARTOS_HW_CALLBACKMAP_H
#define BARTOS_HW_CALLBACKMAP_H

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

#include "callback/AbstractActionMap.h"
#include "callback/AbstractCallbackItem.h"
#include "callback/utils/CallbackType.h"

using std::shared_ptr;
using std::string;
using std::unordered_map;

class ActionMap : public AbstractActionMap<AbstractCallbackItem> {
   public:
    ActionMap() = default;
    ~ActionMap() = default;

    virtual void execute(const string &name);
    virtual void executeAll();

    virtual void add(const string &name, Callback callback);
};

#endif  // BARTOS_HW_CALLBACKMAP_H
