#ifndef CAPABILITY_WITH_VALUE_H
#define CAPABILITY_WITH_VALUE_H

#include "Capability.h"
#include "CapabilityType.h"

template <typename Value, typename Units>
class CapabilityWithValue : public Capability {
   protected:
    Value _value;
    Units _units;

    CapabilityWithValue(const uint8_t &pin, CapabilityType type);

   public:
    ~CapabilityWithValue() = default;

    Value getValue();
    void setValue(Value value);

    Units getUnits();
    void setUnits(Units units);
};

#endif  // CAPABILITY_WITH_VALUE_H