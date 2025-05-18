#include "pubsub_demo.h"

#include <iostream>
#include <string>

void MySubscriber::onNotify(int eventId, void* data)
{
    std::string* msg = static_cast<std::string*>(data);
    std::cout << "[MySubscriber] Received event " << eventId << ": " << (msg ? *msg : "<null>")
              << std::endl;
}

void MyPublisher::doSomething()
{
    std::string msg = "Hello from Publisher!";
    notify(1001, &msg);
}
