#ifndef STATE_CONNECTION_H
#define STATE_CONNECTION_H

#include "ConnectionType.h"

class StateConnection {
private:
    ConnectionType _connectionType;

public:
    explicit StateConnection(ConnectionType type) : _connectionType(type) {}

    ~StateConnection() = default;

    ConnectionType getConnectionType() {
        return _connectionType;
    }

    void setConnectionType(ConnectionType type) {
        _connectionType = type;
    }
};

#endif  //STATE_CONNECTION_H