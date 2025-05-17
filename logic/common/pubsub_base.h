#pragma once
#include <algorithm>
#include <vector>

// Subscriber base class
class Subscriber
{
public:
    virtual ~Subscriber();
    virtual void onNotify(int eventId, void* data) = 0;
};

// Publisher base class
class Publisher
{
public:
    void subscribe(Subscriber* sub);
    void unsubscribe(Subscriber* sub);

protected:
    void notify(int eventId, void* data);

private:
    std::vector<Subscriber*> subscribers;
};
