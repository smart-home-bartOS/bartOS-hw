#ifndef HTTP_MANAGE_DEVICE_CONNECTOR_H
#define HTTP_MANAGE_DEVICE_CONNECTOR_H

#include <HttpClient.h>
#include <connector/DataConnector.h>
#include <connector/ManageConnector.h>

#include <string>

using std::string;

class HttpConnector : public DataConnector, public ManageConnector {
   private:
    HttpClient &_httpClient;

    static bool isValidResponseCode(const int code, const vector<int> &allowedResponseCodes);
    static DynamicJsonDocument getJsonFromResponse(HttpResponse &response, const vector<int> &allowedResponseCodes);
    OnlineDevice *device();

   public:
    explicit HttpConnector(HttpClient &httpClient, const string &baseURL);
    ~HttpConnector() = default;

    void init() override;
    void loop() override;

    void connect() override;
    void create() override;
    void remove() override;
    void update() override;
    void disconnect() override;

    void sendData(const string &path, DynamicJsonDocument &data) override;
};

#endif  // HTTP_MANAGE_DEVICE_CONNECTOR_H