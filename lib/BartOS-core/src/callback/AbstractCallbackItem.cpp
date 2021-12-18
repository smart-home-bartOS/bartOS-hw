#include "callback/AbstractCallbackItem.h"

AbstractCallbackItem::AbstractCallbackItem(Callback callback) : _callback(callback) {
}

void AbstractCallbackItem::execute() {
    if (isEnabled()) {
        _callback();
    }
}

void AbstractCallbackItem::setCallback(Callback callback) {
    _callback = callback;
}

bool AbstractCallbackItem::isEnabled() {
    return _enabled;
}

void AbstractCallbackItem::setEnabled(bool state) {
    _enabled = state;
}