#include "state/NewDeviceState.h"

using std::move;

NewDeviceState::NewDeviceState(OnlineDevice* device) : ConnectionState(device) {}

void NewDeviceState::init() {
}

void NewDeviceState::loop() {
}