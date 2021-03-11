#ifndef CAPABILITY_WITH_VALUE_H
#define CAPABILITY_WITH_VALUE_H

#include <string>

#include "Capability.h"
#include "CapabilityType.h"
using namespace std;

template <typename Value, typename Units>
class CapabilityWithValue : public Capability {
   protected:
    Value _value;
    Units _units;

    CapabilityWithValue(const string &name, const uint8_t &pin, CapabilityType type);
    CapabilityWithValue(const string &name, const uint8_t &pin, CapabilityType type, const unsigned sampleTime);

   public:
    static const string VALUE_FIELD;
    static const string UNITS_FIELD;

    ~CapabilityWithValue() = default;

    Value getValue();
    void setValue(Value value);

    Units getUnits();
    void setUnits(Units units);
};

const string CapabilityWithValue<void, void>::VALUE_FIELD = "value";
const string CapabilityWithValue<void, void>::UNITS_FIELD = "units";

#endif  // CAPABILITY_WITH_VALUE_H