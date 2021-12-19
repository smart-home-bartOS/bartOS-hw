#ifndef BARTOS_HW_HTTP_CLIENT_H
#define BARTOS_HW_HTTP_CLIENT_H

#include <string>

#include "HttpResponse.h"

using std::string;

enum class HttpMethod {
    GET,
    POST,
    PATCH,
    PUT,
    DELETE
};

class HttpClient {
   protected:
    string _serverURL = "";

    virtual HttpResponse execute(HttpMethod method, const string &path);

    virtual HttpResponse execute(HttpMethod method, const string &path, const string &body) = 0;

   public:
    HttpClient(const string &serverURL);

    HttpClient() = default;

    ~HttpClient() = default;

    string getServerURL();

    void setServerURL(const string &serverURL);

    virtual HttpResponse doGet(const string &path);

    virtual HttpResponse doPost(const string &path, const string &body);

    virtual HttpResponse doPatch(const string &path, const string &body);

    virtual HttpResponse doDelete(const string &path);

    virtual HttpResponse doDelete(const string &path, const string &body);
};

#endif  // BARTOS_HW_HTTP_CLIENT_H