//
// Created by mabartos on 4/10/21.
//

#ifndef BARTOS_HW_CALLBACKTIME_H
#define BARTOS_HW_CALLBACKTIME_H

#include <stdint.h>
#include "CallbackUtils.h"

class CallbackTime {
private:
    uint32_t _time;
    Callback _callback;
    bool _enabled=true;
    unsigned long _resultMillis;

    void setNewResultExecuteTime(unsigned long systemTime);
    void setNewResultExecuteTime(uint32_t time);

public:
    CallbackTime(uint32_t time, Callback callback);

    ~CallbackTime() = default;

    uint32_t getTime();

    void setTime(uint32_t time);

    void checkAndExecute(unsigned long systemTime);

    void setCallback(Callback callback);

    bool isEnabled();

    void setEnabled(bool state);

    unsigned long getSystemTime();
};


#endif //BARTOS_HW_CALLBACKTIME_H
