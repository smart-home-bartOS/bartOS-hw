#ifndef BARTOS_HW_NEW_DEVIDE_STATE_H
#define BARTOS_HW_NEW_DEVIDE_STATE_H

#include "ConnectionState.h"

class NewDeviceState : public ConnectionState {
   public:
    NewDeviceState(OnlineDevice* device);
    ~NewDeviceState() = default;

    void init() override;
    void loop() override;
};

#endif  // BARTOS_HW_NEW_DEVIDE_STATE_H