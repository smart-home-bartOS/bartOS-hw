#include "CapabilityWithValue.h"

template <typename Value, typename Units>
CapabilityWithValue<Value, Units>::CapabilityWithValue(const uint8_t &pin, CapabilityType type) : Capability(pin, type) {
}

template <typename Value, typename Units>
Value CapabilityWithValue<Value, Units>::getValue() {
    return _value;
}

template <typename Value, typename Units>
void CapabilityWithValue<Value, Units>::setValue(Value value) {
    _value = value;
}

template <typename Value, typename Units>
Units CapabilityWithValue<Value, Units>::getUnits() {
    return _units;
}
template <typename Value, typename Units>
void CapabilityWithValue<Value, Units>::setUnits(Units units) {
    _units = units;
}