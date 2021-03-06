#ifndef DATA_CONNECTOR_H
#define DATA_CONNECTOR_H

class DataConnector : public DeviceConnector {
   public:
    virtual ~DataConnector(){};

    virtual void connect() = 0;
    virtual void disconnect() = 0;
};

#endif  //DATA_CONNECTOR_H