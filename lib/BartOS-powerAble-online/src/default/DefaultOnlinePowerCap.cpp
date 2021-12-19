//
// Created by mabartos on 4/19/21.
//

#include "default/DefaultOnlinePowerCap.h"

DefaultOnlinePowerCap::DefaultOnlinePowerCap(const uint8_t &pin,
                                             const string &name) : DefaultPowerCap(pin, name),
                                                                   PowerAbleOnline(this) {
}
