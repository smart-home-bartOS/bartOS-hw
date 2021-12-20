#ifndef BARTOS_HW_ONLINE_CONNECTOR_H
#define BARTOS_HW_ONLINE_CONNECTOR_H

#include <string>

using std::string;

class OnlineDevice;

class OnlineConnector {
   private:
    string _baseURL = "";
    OnlineDevice *_device = nullptr;

   public:
    OnlineConnector() = default;

    OnlineConnector(const string &url);
    ~OnlineConnector() = default;

    virtual void init() = 0;
    virtual void loop() = 0;

    string getBaseURL();

    void setBaseURL(const string &baseURL);

    OnlineDevice *getOnlineDevice();
    void setOnlineDevice(OnlineDevice *device);
};

#endif  // BARTOS_HW_ONLINE_CONNECTOR_H