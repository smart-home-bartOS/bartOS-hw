#ifndef BARTOS_HW_MANAGE_CONNECTOR_H
#define BARTOS_HW_MANAGE_CONNECTOR_H

#include "OnlineConnector.h"

class ManageConnector : public OnlineConnector {
   public:
    ManageConnector(const string& baseURL);

    ManageConnector() = default;
    ~ManageConnector() = default;

    virtual void connect() = 0;
    virtual void create() = 0;
    virtual void remove() = 0;
    virtual void update() = 0;
    virtual void disconnect() = 0;
    virtual bool isConnected() { return false; };  // TODO resolve
};

#endif  // BARTOS_HW_MANAGE_CONNECTOR_H