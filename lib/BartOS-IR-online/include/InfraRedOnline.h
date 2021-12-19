//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_IRONLINEREMOTECAP_H
#define BARTOS_HW_IRONLINEREMOTECAP_H

#include <InfraRedCap.h>
#include <capability/OnlineCapability.h>

class InfraRedOnline : public OnlineCapability<InfraRedCap> {
   public:
    InfraRedOnline(InfraRedCap *capability);

    ~InfraRedOnline() = default;
};

#endif  // BARTOS_HW_IRONLINEREMOTECAP_H
