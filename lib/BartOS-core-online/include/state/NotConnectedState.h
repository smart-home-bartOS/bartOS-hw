#ifndef BARTOS_HW_NOT_CONNECTED_STATE_H
#define BARTOS_HW_NOT_CONNECTED_STATE_H

#include "ConnectionState.h"

class NotConnectedState : public ConnectionState {
   public:
    NotConnectedState(OnlineDevice* device);
    ~NotConnectedState() = default;

    void init() override;
    void loop() override;
};

#endif  // BARTOS_HW_NOT_CONNECTED_STATE_H