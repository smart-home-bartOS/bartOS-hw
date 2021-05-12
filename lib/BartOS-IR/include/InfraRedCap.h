//
// Created by mabartos on 4/11/21.
//

#ifndef BARTOS_HW_INFRARED_CAP_H
#define BARTOS_HW_INFRARED_CAP_H

using namespace std;

#include <string>
#include <stdint.h>
#include <capability/Capability.h>
#include <unordered_map>
#include "callback/IrCallbackMap.h"

class InfraRedCap : public Capability {
private:
    bool _printCodes;
protected:
    shared_ptr<IrCallbackMap> _callbacks;
public:
    InfraRedCap(const uint8_t &pin, const string &name, bool printCodes = false);

    ~InfraRedCap() = default;

    shared_ptr<IrCallbackMap> callbacks();

    bool shouldPrintCodes();

    void setPrintCodes(bool state);
};


#endif //BARTOS_HW_INFRARED_CAP_H
