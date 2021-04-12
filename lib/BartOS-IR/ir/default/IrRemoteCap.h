//
// Created by mabartos on 4/11/21.
//

#ifndef BARTOS_HW_IRREMOTECAP_H
#define BARTOS_HW_IRREMOTECAP_H

#include <ir/InfraRedCap.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <memory>

class IrRemoteCap : public InfraRedCap {
private:
    shared_ptr <IRrecv> _irRecv;
    shared_ptr <decode_results> _results;

public:
    IrRemoteCap(const uint8_t &pin, const string &name);

    ~IrRemoteCap() = default;

    void init();

    void execute();

    bool isSignalPresent();

    uint32_t getSignalValue();

    shared_ptr <decode_results> getResults();
};


#endif //BARTOS_HW_IRREMOTECAP_H
