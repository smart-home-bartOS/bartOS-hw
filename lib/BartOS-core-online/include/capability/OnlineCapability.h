#ifndef BARTOS_HW_ONLINE_CAPABILITY_H
#define BARTOS_HW_ONLINE_CAPABILITY_H

#include <memory>

#include "capability/Capability.h"
#include "connector/DataConnector.h"
#include "connector/DataHandler.h"
#include "json/JsonKeys.h"
#include "json/JsonUtils.h"

using std::shared_ptr;
using std::string;

class OnlineDevice;

template <class TargetCap = Capability>
class OnlineCapability : public DataHandler {
   private:
    long _id = -1;
    shared_ptr<DataConnector> _dataConnector;
    TargetCap* _capability;
    OnlineDevice* _device = nullptr;

   public:
    OnlineCapability(TargetCap* capability) : _capability(capability){};

    ~OnlineCapability() = default;

    void setDevice(OnlineDevice* device) {
        _device = device;
    }

    TargetCap* getTargetCapability() {
        return _capability;
    }

    OnlineDevice* getOnlineDevice() {
        return _device;
    }

    void setOnlineDevice(OnlineDevice* device) {
        _device = device;
    }

    long getID() {
        return _id;
    }

    void setID(long id) {
        _id = id;
    }

    shared_ptr<DataConnector> getDataConnector() {
        return _dataConnector;
    }

    void setDataConnector(shared_ptr<DataConnector> connector) {
        _dataConnector = connector;
    }

    virtual void handleData(DynamicJsonDocument& data) override {
        JsonObject object = data.as<JsonObject>();
        const string KEYS[] = {JsonKeys::ENABLED};
        if (containKeys(object, KEYS)) {
            bool isEnabled = object[JsonKeys::ENABLED];
            getTargetCapability()->setEnabled(isEnabled);
        }
    }

    virtual DynamicJsonDocument getInfo() override {
        DynamicJsonDocument data(100);

        data[JsonKeys::PIN] = getTargetCapability()->getPin();
        data[JsonKeys::NAME] = getTargetCapability()->getName();
        data[JsonKeys::TYPE] = getTargetCapability()->getType();
        data[JsonKeys::ENABLED] = getTargetCapability()->isEnabled();

        data.shrinkToFit();
        data.garbageCollect();
        return data;
    };

    virtual vector<string> getSubscribedPaths() override {
        vector<string> vec;
        return vec;
    }
};

#endif  // BARTOS_HW_ONLINE_CAPABILITY_H