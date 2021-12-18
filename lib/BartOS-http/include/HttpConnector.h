#ifndef HTTP_MANAGE_DEVICE_CONNECTOR_H
#define HTTP_MANAGE_DEVICE_CONNECTOR_H

#include <HttpResponse.h>
#include <connector/DataConnector.h>
#include <connector/ManageConnector.h>

#include <string>

using std::string;

class HttpConnector : public DataConnector, public ManageConnector {
   protected:
    DynamicJsonDocument getJsonFromResponse(HttpResponse &response,
                                            const vector<int> &allowedResponseCodes,
                                            const string allowedKeys[]);
    DynamicJsonDocument getJsonFromResponse(HttpResponse &response, const vector<int> &allowedResponseCodes);

   public:
    explicit HttpConnector(const string &baseURL);
    ~HttpConnector() = default;

    void init() override;
    void loop() override;

    void sendData(const string &path, DynamicJsonDocument &data) override;

    void connect() override;
    void create() override;
    void remove() override;
    void update() override;
    void disconnect() override;
};

#endif  // HTTP_MANAGE_DEVICE_CONNECTOR_H