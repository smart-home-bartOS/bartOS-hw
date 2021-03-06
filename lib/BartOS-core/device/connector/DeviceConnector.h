#ifndef DEVICE_CONNECTOR_H
#define DEVICE_CONNECTOR_H

class DeviceConnector {
   public:
    virtual ~DeviceConnector();
    virtual void connect() = 0;
    virtual void disconnect() = 0;
};

#endif  // DEVICE_CONNECTOR_H