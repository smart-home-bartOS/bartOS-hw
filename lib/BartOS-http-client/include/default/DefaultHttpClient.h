#ifndef BARTOS_HW_DEFAULT_HTTP_CLIENT_H
#define BARTOS_HW_DEFAULT_HTTP_CLIENT_H

#include <ESP8266HTTPClient.h>

#include "HttpClient.h"

class DefaultHttpClient : public HttpClient {
   private:
    WiFiClient &_wifiClient;

   protected:
    HttpResponse execute(HttpMethod method, const string &path, const string &body) override;

   public:
    DefaultHttpClient(WiFiClient &wifiClient, const string &serverURL);
    DefaultHttpClient() = default;
    ~DefaultHttpClient() = default;
};

#endif  // BARTOS_HW_DEFAULT_HTTP_CLIENT_H