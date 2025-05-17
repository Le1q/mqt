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

    return a.exec();
}
