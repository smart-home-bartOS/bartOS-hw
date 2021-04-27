//
// Created by mabartos on 4/10/21.
//

#ifndef BARTOS_HW_CALLBACKTIME_H
#define BARTOS_HW_CALLBACKTIME_H

#include <stdint.h>
#include "core/callback/utils/CallbackType.h"

class CallbackTime {
private:
    uint32_t _time;
    SimpleCallback _callback;
    bool _enabled = true;
    uint32_t _lastExec = 0;
    bool _oneUseOnly=false;

    bool isTimeAchieved();

public:
    CallbackTime(uint32_t time, SimpleCallback callback, bool oneUseOnly = false);

    ~CallbackTime() = default;

    uint32_t getTime();

    void setTime(uint32_t time);

    bool checkAndExecute();

    void setCallback(SimpleCallback callback);

    bool isEnabled();

    bool isOneUseOnly();

    void setEnabled(bool state);

    uint32_t getSystemTime();
};


#endif //BARTOS_HW_CALLBACKTIME_H
