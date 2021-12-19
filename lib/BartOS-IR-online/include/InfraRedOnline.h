//
// Created by mabartos on 4/19/21.
//

#ifndef BARTOS_HW_IRONLINEREMOTECAP_H
#define BARTOS_HW_IRONLINEREMOTECAP_H

#include <InfraRedCap.h>
#include <capability/OnlineCapability.h>

class InfraRedOnline : public OnlineDevice<InfraRedCap> {
   public:
    static const char *VALUE;

    InfraRedOnline(InfraRedCap *capability);

    ~InfraRedOnline() = default;

    DynamicJsonDocument getData() override;
    void handleData(DynamicJsonDocument &data) override;
    vector<string> getSubscribedPaths() override;
};

#endif  // BARTOS_HW_IRONLINEREMOTECAP_H
