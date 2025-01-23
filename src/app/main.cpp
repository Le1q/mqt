// #include "iostream"

// int main() {
//     std::cout << "Hello, World!" << std::endl;
//     return 0;
// }


#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}