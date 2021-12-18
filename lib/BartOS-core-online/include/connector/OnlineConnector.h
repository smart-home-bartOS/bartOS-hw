#ifndef BARTOS_HW_ONLINE_CONNECTOR_H
#define BARTOS_HW_ONLINE_CONNECTOR_H

#include <string>

using std::string;

class OnlineConnector {
   private:
    string _baseURL = "";

   public:
    OnlineConnector() = default;

    OnlineConnector(const string &url);
    ~OnlineConnector() = default;

    virtual void init() = 0;
    virtual void loop() = 0;

    string getBaseURL();

    void setBaseURL(const string &baseURL);
};

#endif  // BARTOS_HW_ONLINE_CONNECTOR_H