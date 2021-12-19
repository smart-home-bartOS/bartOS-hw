//
// Created by mabartos on 4/19/21.
//

#include "default/DefaultOnlineLightsCap.h"

DefaultOnlineLightsCap::DefaultOnlineLightsCap(const uint8_t &pin,
                                               const string &name,
                                               uint32_t pwmRange) : DefaultLightsCap(pin, name, pwmRange),
                                                                    LightsOnline(this) {
}