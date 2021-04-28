//
// Created by mabartos on 4/28/21.
//

#include "Capabilities.h"

shared_ptr <DhtTempSensor> RoomTemp = make_shared<DhtTempSensor>(ROOM_TEMP_PIN, 22);
shared_ptr <DhtHumSensor> RoomHum = make_shared<DhtHumSensor>(ROOM_HUM_PIN, 22);

void setupTempHumRules() {
    Capabilities.push_back(RoomTemp);
    Capabilities.push_back(RoomHum);
}