//
// Created by mabartos on 4/10/21.
//

#ifndef BARTOS_HW_TIME_ACTION_MAP_H
#define BARTOS_HW_TIME_ACTION_MAP_H

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

#include "AbstractActionMap.h"
#include "CallbackTime.h"
#include "callback/utils/CallbackType.h"

using std::shared_ptr;
using std::string;
using std::unordered_map;

class TimeActionMap : public AbstractActionMap<CallbackTime> {
   public:
    TimeActionMap() = default;
    ~TimeActionMap() = default;

    void loop();

    void timer(const string &name, uint32_t time, Callback callback);

    void period(const string &name, uint32_t time, Callback callback);

    void update(const string &name, uint32_t time, Callback callback);
};

#endif  // BARTOS_HW_TIME_ACTION_MAP_H
