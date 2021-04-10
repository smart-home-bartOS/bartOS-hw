//
// Created by mabartos on 3/31/21.
//

#ifndef BARTOS_HW_CALLBACKMAP_H
#define BARTOS_HW_CALLBACKMAP_H
using namespace std;

#include <iostream>
#include <unordered_map>
#include <string>
#include "CallbackUtils.h"

class CallbackMap {
private:
    unordered_map<string, Callback> _callbacks;
public:
    CallbackMap() = default;

    ~CallbackMap() = default;

    void executeAll();

    void execute(const string &name);

    void clearAll();

    void add(const string &name, Callback callback);

    void remove(const string &name);

    uint32_t getSize();
};


#endif //BARTOS_HW_CALLBACKMAP_H
