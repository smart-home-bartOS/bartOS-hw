//
// Created by mabartos on 4/11/21.
//

#ifndef BARTOS_HW_IRREMOTECAP_H
#define BARTOS_HW_IRREMOTECAP_H

#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include <IRutils.h>

#include <memory>

#include "InfraRedCap.h"

class DefaultIRCap : public InfraRedCap {
   private:
    shared_ptr<IRrecv> _irRecv;
    shared_ptr<decode_results> _results;

   public:
    DefaultIRCap(const uint8_t &pin);

    ~DefaultIRCap() = default;

    void init();

    void loop();
};

#endif  // BARTOS_HW_IRREMOTECAP_H
