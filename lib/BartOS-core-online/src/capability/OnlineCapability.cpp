#include "capability/OnlineCapability.h"

OnlineCapability::OnlineCapability(const uint8_t &pin,
                                   const string &type,
                                   const string &name,
                                   const unsigned sampleTime)
    : DataHandler(), Capability(pin, type, name, sampleTime){};

long OnlineCapability::getID() {
    return _id;
}
void OnlineCapability::setID(long id) {
    _id = id;
}

shared_ptr<DataConnector> OnlineCapability::getDataConnector() {
    return _dataConnector;
}

void OnlineCapability::setDataConnector(shared_ptr<DataConnector> connector) {
    _dataConnector = connector;
}