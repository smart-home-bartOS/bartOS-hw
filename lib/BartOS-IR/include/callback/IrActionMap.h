//
// Created by mabartos on 4/27/21.
//

#ifndef BARTOS_HW_IRCALLBACKMAP_H
#define BARTOS_HW_IRCALLBACKMAP_H

#include <callback/ActionMap.h>

class IrActionMap : public ActionMap {
   public:
    IrActionMap() = default;

    ~IrActionMap() = default;

    void executeAll() override{};
};

#endif  // BARTOS_HW_IRCALLBACKMAP_H
