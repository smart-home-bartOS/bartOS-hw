//
// Created by mabartos on 3/28/21.
//

#ifndef BARTOS_HW_CAPABILITIES_H
#define BARTOS_HW_CAPABILITIES_H

#include <vector>
#include <memory>

shared_ptr<DhtTempSensor> temp = make_shared<DhtTempSensor>(D7, 22);
shared_ptr<DhtTempSensor> temp2 = make_shared<DhtTempSensor>(D8, 22);

template<class Callback>
void handleCallback(bool condition, Callback callback) {
    if (condition) {
        callback();
    }
}

/* Capabilities */
vector<shared_ptr<Capability>> capabilities{
        temp,
        temp2,
};

void handleAllCallbacks() {
    handleCallback(temp->getTemperature() >= 25.0, []() -> void {
        //TEST1
    });

    handleCallback(temp->getTemperature() >= 15.0, []() -> void {
        //TEST2
    });

    handleCallback(temp->getTemperature() <= 25.0, []() -> void {
        //TEST3
    });
}

#endif //BARTOS_HW_CAPABILITIES_H
