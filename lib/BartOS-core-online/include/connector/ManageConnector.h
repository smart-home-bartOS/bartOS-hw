#ifndef BARTOS_HW_MANAGE_CONNECTOR_H
#define BARTOS_HW_MANAGE_CONNECTOR_H

#include <ArduinoJson.h>

#include "OnlineConnector.h"

class ManageConnector : public OnlineConnector {
   private:
    void setUpCapabilities(DynamicJsonDocument& data);

   protected:
    virtual void handleMessageConnect();
    virtual void handleMessageCreate();
    virtual void handleMessageRemove();
    virtual void handleMessageUpdate();
    virtual void handleMessageDisconnect();

   public:
    ManageConnector(const string& baseURL);

    ManageConnector() = default;
    ~ManageConnector() = default;

    virtual void init() override;

    virtual void connect() = 0;
    virtual void create() = 0;
    virtual void remove() = 0;
    virtual void update() = 0;
    virtual void disconnect() = 0;

    static string CREATE_HANDLER;
    static string CONNECT_HANDLER;
    static string REMOVE_HANDLER;
    static string UPDATE_HANDLER;
    static string DISCONNECT_HANDLER;
};

#endif  // BARTOS_HW_MANAGE_CONNECTOR_H