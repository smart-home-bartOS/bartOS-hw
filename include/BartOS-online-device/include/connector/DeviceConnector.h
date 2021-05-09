#ifndef DEVICE_CONNECTOR_H
#define DEVICE_CONNECTOR_H
using namespace std;

#include <string>
#include <memory>
#include <utility>

class DeviceConnector {
private:
    string _url;
public:
    DeviceConnector() = default;

    virtual ~DeviceConnector() = default;

    void setUrl(const string &url) {
        _url = url;
    }

    string getUrl() {
        return _url;
    }

    virtual void connect() = 0;

    virtual void disconnect() = 0;

    virtual void init() {};

    virtual void loop() {};
};

#endif  // DEVICE_CONNECTOR_H