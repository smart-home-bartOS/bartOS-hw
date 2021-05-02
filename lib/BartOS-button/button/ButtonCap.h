//
// Created by mabartos on 4/11/21.
//

#ifndef BARTOS_HW_BUTTONCAP_H
#define BARTOS_HW_BUTTONCAP_H

#include <core/capability/Capability.h>
#include <vector>
#include <core/callback/utils/CallbackType.h>

#define DEFAULT_DELAY_MILLIS 50

class ButtonCap : public Capability {
private:
    bool _prevState;

    vector<SimpleCallback> _onChangeCallbacks;
    vector<SimpleCallback> _onOnCallbacks;
    vector<SimpleCallback> _onOffCallbacks;

protected:
    bool _state;

    virtual void updateState() = 0;

    void executeOnChangeCallbacks();

    void executeOnStateOnCallbacks();

    void executeOnStateOffChangeCallbacks();

public:
    ButtonCap(const uint8_t &pin, const string &name);

    ~ButtonCap() = default;

    void init() override;

    void execute() override;

    bool isOn();

    bool isOff();

    virtual bool isChanged();

    void onChange(SimpleCallback callback);

    void onStateOn(SimpleCallback callback);

    void onStateOff(SimpleCallback callback);
};

#endif //BARTOS_HW_BUTTONCAP_H
