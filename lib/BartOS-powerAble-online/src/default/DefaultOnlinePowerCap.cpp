//
// Created by mabartos on 4/19/21.
//

#include "default/DefaultOnlinePowerCap.h"

DefaultOnlinePowerCap::DefaultOnlinePowerCap(const uint8_t &pin) : DefaultPowerCap(pin),
                                                                   PowerAbleOnline(this) {
}
