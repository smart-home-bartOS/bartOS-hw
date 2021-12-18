#ifndef BARTOS_HW_CONNECTED_STATE_H
#define BARTOS_HW_CONNECTED_STATE_H

#include "ConnectionState.h"

class ConnectedState : public ConnectionState {
   public:
    ConnectedState(OnlineDevice* device);
    ~ConnectedState() = default;

    void init() override;
    void loop() override;
};

#endif  // BARTOS_HW_CONNECTED_STATE_H