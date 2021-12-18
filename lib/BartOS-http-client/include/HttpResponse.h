#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

#include <ArduinoJson.h>

#include <string>

using std::string;

class HttpResponse {
   private:
    int _code;
    string _payload;

   public:
    HttpResponse() = default;

    HttpResponse(const int &code, const string &payload);

    ~HttpResponse() = default;

    int getResponseCode();

    void setResponseCode(int code);

    string &getPayload();

    DynamicJsonDocument &getPayloadJSON();

    void setPayload(const string &payload);

    void setPayload(const char *payload);
};

#endif  // HTTP_RESPONSE_H