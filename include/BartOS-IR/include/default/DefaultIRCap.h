//
// Created by mabartos on 4/11/21.
//

#ifndef BARTOS_HW_IRREMOTECAP_H
#define BARTOS_HW_IRREMOTECAP_H

#include "InfraRedCap.h"
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <memory>

class DefaultIRCap : public InfraRedCap {
private:
    shared_ptr <IRrecv> _irRecv;
    shared_ptr <decode_results> _results;

public:
    DefaultIRCap(const uint8_t &pin, const string &name = "IR_Recv");

    ~DefaultIRCap() = default;

    void init();

    void execute();
};


#endif //BARTOS_HW_IRREMOTECAP_H
