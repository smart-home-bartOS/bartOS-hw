//
// Created by mabartos on 3/28/21.
//

#ifndef BARTOS_HW_UTILS_H
#define BARTOS_HW_UTILS_H

#include <stdint.h>

template<class CallbackType>
void handleCallback(bool condition, CallbackType callback) {
    if (condition) {
        callback();
    }
}

#endif //BARTOS_HW_UTILS_H
