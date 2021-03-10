#ifndef DEVICE_CONNECTOR_H
#define DEVICE_CONNECTOR_H

#include <memory>

#include "core/device/Device.h"

class DeviceConnector {
   private:
    shared_ptr<Device> _device;

   public:
    virtual ~DeviceConnector();
    virtual void connect() = 0;
    virtual void disconnect() = 0;

    void setDevice(shared_ptr<Device> device) {
        _device = device;
    };

    shared_ptr<Device> getDevice() {
        return _device;
    }
};

#endif  // DEVICE_CONNECTOR_H