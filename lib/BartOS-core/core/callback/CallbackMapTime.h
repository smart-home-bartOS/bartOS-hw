//
// Created by mabartos on 4/10/21.
//

#ifndef BARTOS_HW_CALLBACK_MAP_TIME_H
#define BARTOS_HW_CALLBACK_MAP_TIME_H

#include "CallbackUtils.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include "CallbackMap.h"
#include "CallbackTime.h"

class CallbackMapTime : public CallbackMap {
private:
    unordered_map<string, CallbackTime> _timeCallbacks;

    void changeEnableState(const string &name, bool state);

public:
    CallbackMapTime();

    ~CallbackMapTime() = default;

    void executeAll();

    void period(const string &name, uint32_t time, Callback callback);

    void changePeriodTime(const string &name, uint32_t time);

    void stopPeriod(const string &name);

    void resumePeriod(const string &name);

    void removePeriod(const string &name);

    unsigned long getSystemTime();

    uint32_t getSize();
};


#endif //BARTOS_HW_CALLBACK_MAP_TIME_H
