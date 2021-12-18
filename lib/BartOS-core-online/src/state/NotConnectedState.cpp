#include "state/NotConnectedState.h"

using std::move;

NotConnectedState::NotConnectedState(OnlineDevice* device) : ConnectionState(device) {}

void NotConnectedState::init() {
}

void NotConnectedState::loop() {
}