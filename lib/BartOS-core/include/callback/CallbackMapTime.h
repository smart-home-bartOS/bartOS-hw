//
// Created by mabartos on 4/10/21.
//

#ifndef BARTOS_HW_CALLBACK_MAP_TIME_H
#define BARTOS_HW_CALLBACK_MAP_TIME_H

#include "callback/utils/CallbackType.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>
#include "CallbackMap.h"
#include "CallbackTime.h"

class CallbackMapTime : public CallbackMap {
private:
    unordered_map<string, shared_ptr<CallbackTime>> _timeCallbacks;

    void changeEnableState(const string &name, bool state);

public:
    CallbackMapTime();

    ~CallbackMapTime() = default;

    void executeAll();

    void timer(const string &name, uint32_t time, SimpleCallback callback);

    void period(const string &name, uint32_t time, SimpleCallback callback);

    void update(const string &name, uint32_t time, SimpleCallback callback);

    void enable(const string &name);

    void disable(const string &name);

    uint32_t getSize();

    bool existsCallback(const string &name) override;
};


#endif //BARTOS_HW_CALLBACK_MAP_TIME_H
