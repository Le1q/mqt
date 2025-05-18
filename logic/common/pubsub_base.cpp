#include "pubsub_base.h"

Subscriber::~Subscriber() = default;

void Publisher::subscribe(Subscriber* sub) {
    subscribers.push_back(sub);
}

void Publisher::unsubscribe(Subscriber* sub) {
    subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), sub), subscribers.end());
}

void Publisher::notify(int eventId, void* data) {
    for (auto* sub : subscribers) {
        if (sub) sub->onNotify(eventId, data);
    }
}
