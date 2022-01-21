//
// Created by mabartos on 4/13/21.
//

#ifndef BARTOS_HW_DHTTEMPONLINE_H
#define BARTOS_HW_DHTTEMPONLINE_H

#include <default/DhtTempSensor.h>

#include "TemperatureOnline.h"

class DhtTempOnline : public DhtTempSensor, public TemperatureOnline {
   public:
    DhtTempOnline(const uint8_t &pin,
                  const uint8_t &dhtType);

    ~DhtTempOnline() = default;
};

#endif  // BARTOS_HW_DHTTEMPONLINE_H
