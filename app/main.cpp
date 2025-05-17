#include <QApplication>

#include "logic.h"
#include "logic/code/pubsub_demo.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Logic logic;
    int result = logic.add(2, 3);  // Example usage
    MainWindow w;
    w.setWindowTitle(QString("Peace & Love").arg(result));
    w.show();

    // 发布订阅演示
    MyPublisher publisher;
    MySubscriber subscriber;
    publisher.subscribe(&subscriber);
    publisher.doSomething();

    return a.exec();
}
