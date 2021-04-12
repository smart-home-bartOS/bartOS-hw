#ifndef DEVICE_CONNECTOR_H
#define DEVICE_CONNECTOR_H

#include <memory>
#include <utility>

class DeviceConnector {
public:
    virtual ~DeviceConnector() = default;

    virtual void connect() = 0;

    virtual void disconnect() = 0;
};

#endif  // DEVICE_CONNECTOR_H