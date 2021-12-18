#ifndef BARTOS_HW_CONNECTION_STATE_H
#define BARTOS_HW_CONNECTION_STATE_H

#include "device/OnlineDevice.h"

using std::move;
using std::shared_ptr;

class OnlineDevice;

class ConnectionState {
   protected:
    OnlineDevice* _device;

   public:
    ConnectionState(OnlineDevice* device) : _device(move(device)){};
    ~ConnectionState() = default;

    virtual void init() = 0;
    virtual void loop() = 0;
};

#endif  // BARTOS_HW_CONNECTION_STATE_H