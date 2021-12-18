#ifndef BARTOS_HW_ABSTRACT_CALLBACK_ITEM_H
#define BARTOS_HW_ABSTRACT_CALLBACK_ITEM_H

#include <stdint.h>

#include "callback/utils/CallbackType.h"

class AbstractCallbackItem {
   private:
    Callback _callback;
    bool _enabled = true;

   public:
    AbstractCallbackItem(Callback callback);
    ~AbstractCallbackItem() = default;

    virtual void execute();
    void setCallback(Callback callback);
    bool isEnabled();
    void setEnabled(bool state);
};

#endif  // BARTOS_HW_ABSTRACT_CALLBACK_ITEM_H