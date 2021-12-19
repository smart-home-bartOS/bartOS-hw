//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_DHTHUMONLINE_H
#define BARTOS_HW_DHTHUMONLINE_H

#include <HumidityOnline.h>
#include <default/DhtHumSensor.h>

class DhtHumOnline : public DhtHumSensor, public HumidityOnline {
   public:
    DhtHumOnline(const uint8_t &pin,
                 const uint8_t &dhtType,
                 const string &name = DEFAULT_NAME);

    ~DhtHumOnline() = default;
};

#endif  // BARTOS_HW_DHTHUMONLINE_H
