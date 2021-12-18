#ifndef BARTOS_HW_I_ACTION_MAP_H
#define BARTOS_HW_I_ACTION_MAP_H
#include <memory>
#include <string>
#include <unordered_map>

#include "AbstractCallbackItem.h"

using std::shared_ptr;
using std::string;
using std::unordered_map;

// template <typename Item, typename std::enable_if<std::is_base_of<AbstractCallbackItem, Item>::value>::type * = nullptr>
template <class Item>
class AbstractActionMap {
   private:
    unordered_map<string, shared_ptr<Item>> _callbacks;
    virtual void changeEnableState(const string &name, bool state) {
        auto it = _callbacks.find(name);
        if (it != _callbacks.end()) {
            it->second->setEnabled(state);
        }
    }

   public:
    AbstractActionMap() = default;
    ~AbstractActionMap() = default;

    unordered_map<string, shared_ptr<Item>> getCallbacks() {
        return _callbacks;
    }

    virtual void loop() = 0;

    virtual void enable(const string &name) {
        changeEnableState(name, true);
    }

    virtual void disable(const string &name) {
        changeEnableState(name, false);
    };
    virtual void remove(const string &name) {
        _callbacks.erase(name);
    }

    virtual void removeAll() {
        _callbacks.clear();
    }

    virtual uint32_t getSize() {
        return _callbacks.size();
    }

    virtual bool existsCallback(const string &name) {
        if (name.empty()) return false;
        auto it = _callbacks.find(name);
        return it != _callbacks.end();
    }
};

#endif  // BARTOS_HW_I_ACTION_MAP_H