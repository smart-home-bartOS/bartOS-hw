#ifndef BARTOS_HW_CONNECTION_STATE_H
#define BARTOS_HW_CONNECTION_STATE_H

class ConnectionState {
   private:
    OnlineDevice &device;

   public:
    ConnectionState() = default;
    ~ConnectionState() = default;

    virtual void init() = 0;
    virtual void loop() = 0;
}

#endif  // BARTOS_HW_CONNECTION_STATE_H