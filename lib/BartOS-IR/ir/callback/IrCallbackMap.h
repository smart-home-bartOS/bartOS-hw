//
// Created by mabartos on 4/27/21.
//

#ifndef BARTOS_HW_IRCALLBACKMAP_H
#define BARTOS_HW_IRCALLBACKMAP_H

#include "core/callback/CallbackMap.h"

class IrCallbackMap : public CallbackMap {
public:
    IrCallbackMap() = default;

    ~IrCallbackMap() = default;

    void executeAll() override {};
};


#endif //BARTOS_HW_IRCALLBACKMAP_H
