#ifndef BARTOS_HW_ONLINE_CAPABILITY_H
#define BARTOS_HW_ONLINE_CAPABILITY_H

#include <capability/Capability.h>

#include <memory>

#include "connector/DataConnector.h"
#include "connector/DataHandler.h"

using std::shared_ptr;
using std::string;

class OnlineCapability : public DataHandler, public Capability {
   private:
    long _id = -1;
    shared_ptr<DataConnector> _dataConnector;

   public:
    OnlineCapability(const uint8_t &pin,
                     const string &type = CapabilityType::OTHER,
                     const string &name = "OnlineCap-unknown",
                     const unsigned sampleTime = 0);

    ~OnlineCapability() = default;

    long getID();
    void setID(long id);

    shared_ptr<DataConnector> getDataConnector();
    void setDataConnector(shared_ptr<DataConnector> connector);
};

#endif  // BARTOS_HW_ONLINE_CAPABILITY_H