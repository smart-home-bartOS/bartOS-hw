#ifndef BARTOS_HW_ONLINE_CAPABILITY_H
#define BARTOS_HW_ONLINE_CAPABILITY_H

#include <memory>

#include "connector/DataConnector.h"
#include "connector/DataHandler.h"

using std::shared_ptr;
using std::string;

class OnlineDevice;

template <class TargetCap>
class OnlineCapability : public DataHandler {
   private:
    long _id = -1;
    shared_ptr<DataConnector> _dataConnector;
    TargetCap* _capability;
    OnlineDevice* _device = nullptr;

   public:
    OnlineCapability(TargetCap* capability) : _capability(capability){};

    ~OnlineCapability() = default;

    void setDevice(OnlineDevice* device) {
        _device = device;
    }

    TargetCap* getTargetCapability() {
        return _capability;
    }

    OnlineDevice* getOnlineDevice() {
        return _device;
    }

    void setOnlineDevice(OnlineDevice* device) {
        _device = device;
    }

    long getID() {
        return _id;
    }

    void setID(long id) {
        _id = id;
    }

    shared_ptr<DataConnector> getDataConnector() {
        return _dataConnector;
    }

    void setDataConnector(shared_ptr<DataConnector> connector) {
        _dataConnector = connector;
    }
};

#endif  // BARTOS_HW_ONLINE_CAPABILITY_H