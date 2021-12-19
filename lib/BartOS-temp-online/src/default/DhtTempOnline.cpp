//
// Created by mabartos on 4/13/21.
//

#include "default/DhtTempOnline.h"

DhtTempOnline::DhtTempOnline(const uint8_t &pin,
                             const uint8_t &dhtType,
                             const string &name) : DhtTempSensor(pin, dhtType, name),
                                                   TemperatureOnline(this) {
}