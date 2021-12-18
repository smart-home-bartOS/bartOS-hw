//
// Created by mabartos on 4/10/21.
//

#ifndef BARTOS_HW_CALLBACKTIME_H
#define BARTOS_HW_CALLBACKTIME_H

#include <stdint.h>

#include "callback/AbstractCallbackItem.h"
#include "callback/utils/CallbackType.h"

class CallbackTime : public AbstractCallbackItem {
   private:
    uint32_t _time;
    uint32_t _lastExec = 0;
    bool _oneUseOnly = false;

    bool isTimeAchieved();
    uint32_t getSystemTime();

   public:
    CallbackTime(uint32_t time, Callback callback, bool oneUseOnly = false);

    ~CallbackTime() = default;

    void execute();

    uint32_t getTime();

    void setTime(uint32_t time);

    bool isOneUseOnly();
};

#endif  // BARTOS_HW_CALLBACKTIME_H
