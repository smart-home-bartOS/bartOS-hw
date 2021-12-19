//
// Created by mabartos on 4/11/21.
//

#ifndef BARTOS_HW_IRREMOTECAP_H
#define BARTOS_HW_IRREMOTECAP_H


#include <IRremoteESP8266.h>
#include <IRutils.h>
#include <IRrecv.h>
#include <memory>

#include "InfraRedCap.h"

class DefaultIRCap : public InfraRedCap {
   private:
    shared_ptr<IRrecv> _irRecv;
    shared_ptr<decode_results> _results;

   public:
    DefaultIRCap(const uint8_t &pin, const string &name = "IR_Recv");

    ~DefaultIRCap() = default;

    void init();

    void loop();
};

#endif  // BARTOS_HW_IRREMOTECAP_H
