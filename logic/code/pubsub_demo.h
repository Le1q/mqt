#pragma once
#include <iostream>

#include "../common/pubsub_base.h"

class MySubscriber : public Subscriber {
public:
    void onNotify(int eventId, void* data) override;
};

class MyPublisher : public Publisher {
public:
    void doSomething();
};
