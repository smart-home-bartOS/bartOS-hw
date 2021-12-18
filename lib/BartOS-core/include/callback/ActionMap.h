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
   private:
    // unordered_map<string, shared_ptr<AbstractCallbackItem>> _callbacks;

    void changeEnableState(const string &name, bool state);

   public:
    ActionMap() = default;
    ~ActionMap() = default;

    void execute(const string &name);
    void loop();

    void add(const string &name, Callback callback);

    // Interface
    /* void enable(const string &name);

    void disable(const string &name);

    void remove(const string &name);

    void removeAll();

    uint32_t getSize();

    bool existsCallback(const string &name);*/
};

#endif  // BARTOS_HW_CALLBACKMAP_H
