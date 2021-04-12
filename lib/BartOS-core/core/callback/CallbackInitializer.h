//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_CALLBACKINITIALIZER_H
#define BARTOS_HW_CALLBACKINITIALIZER_H

using namespace std;

#include <string>
#include <unordered_map>
#include "core/callback/utils/CallbackType.h"

class CallbackInitializer {
private:
    unordered_map<string, SimpleCallback> _callbacks;
public:
    CallbackInitializer() = default;

    ~CallbackInitializer() = default;

    void add(const string &name, SimpleCallback callback);
};


#endif //BARTOS_HW_CALLBACKINITIALIZER_H
