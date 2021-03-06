//
// Created by mabartos on 3/31/21.
//

#ifndef BARTOS_HW_CALLBACKMAP_H
#define BARTOS_HW_CALLBACKMAP_H
using namespace std;

#include <iostream>
#include <unordered_map>
#include <string>
#include "callback/utils/CallbackType.h"

class CallbackMap {
private:
    unordered_map<string, SimpleCallback> _callbacks;

public:
    CallbackMap() = default;

    ~CallbackMap() = default;

    virtual void executeAll();

    virtual void execute(const string &name);

    virtual void clearAll();

    virtual void add(const string &name, SimpleCallback callback);

    virtual void remove(const string &name);

    uint32_t getSize();

    virtual bool existsCallback(const string &name);
};


#endif //BARTOS_HW_CALLBACKMAP_H
