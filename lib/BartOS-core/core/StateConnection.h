#ifndef STATE_CONNECTION_H
#define STATE_CONNECTION_H

#include "ConnectionType.h"

class StateConnection {
private:
    ConnectionType _connectionType;

protected:
    void setConnectionType(ConnectionType type) {
        _connectionType = type;
    }

public:
    explicit StateConnection(ConnectionType type) : _connectionType(type) {}

    ~StateConnection() = default;

    ConnectionType getConnectionType() {
        return _connectionType;
    }
};

#endif  //STATE_CONNECTION_H