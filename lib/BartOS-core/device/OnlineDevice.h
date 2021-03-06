#ifndef ONLINE_DEVICE_H
#define ONLINE_DEVICE_H

#include "Device.h"
#include "connector/DataConnector.h"
#include "connector/ManageConnector.h"

class OnlineDevice : public Device {
   private:
    bool _storeFileSystem = false;
    shared_ptr<ManageConnector> _manageConnector;
    shared_ptr<DataConnector> _dataConnector;

   public:
    OnlineDevice(shared_ptr<ManageConnector> &manageConn,
                 shared_ptr<DataConnector> &dataConn);
    OnlineDevice(shared_ptr<ManageConnector> &manageConn,
                 shared_ptr<DataConnector> &dataConn,
                 bool storeToFileSystem);
    ~OnlineDevice() = default;

    void init();

    bool createDevice();
    bool connectDevice();
    bool disconnectDevice();

    bool shouldSaveToFileSystem();

    shared_ptr<ManageConnector> getManageConnector();
    shared_ptr<DataConnector> getDataConnector();
};

#endif  //ONLINE_DEVICE_H