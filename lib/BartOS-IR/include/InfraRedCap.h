//
// Created by mabartos on 4/11/21.
//

#ifndef BARTOS_HW_INFRARED_CAP_H
#define BARTOS_HW_INFRARED_CAP_H

#include <callback/ActionMap.h>
#include <capability/Capability.h>
#include <stdint.h>

#include <string>
#include <unordered_map>

#include "callback/IrActionMap.h"

class InfraRedCap : public Capability {
   private:
    bool _printCodes;
    shared_ptr<ActionMap> _onDecode;

   protected:
    shared_ptr<IrActionMap> _callbacks;

   public:
    InfraRedCap(const uint8_t &pin, const string &name, bool printCodes = false);

    ~InfraRedCap() = default;

    shared_ptr<IrActionMap> codeHandler();

    shared_ptr<ActionMap> onDecode();

    bool shouldPrintCodes();

    void setPrintCodes(bool state);
};

#endif  // BARTOS_HW_INFRARED_CAP_H
