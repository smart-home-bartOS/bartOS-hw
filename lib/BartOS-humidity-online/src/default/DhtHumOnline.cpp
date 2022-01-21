//
// Created by mabartos on 4/19/21.
//

#include "default/DhtHumOnline.h"

DhtHumOnline::DhtHumOnline(const uint8_t &pin,
                           const uint8_t &dhtType) : DhtHumSensor(pin, dhtType),
                                                     HumidityOnline(this) {
}