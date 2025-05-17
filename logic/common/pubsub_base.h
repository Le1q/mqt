#pragma once
#include <algorithm>
#include <vector>

// 订阅者基类
class Subscriber
{
public:
    virtual ~Subscriber();
    virtual void onNotify(int eventId, void* data) = 0;
};

// 发布者基类
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
