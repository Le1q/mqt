#include "mainwindow.h"

#include <QMessageBox>
#include <QString>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    publisherM.subscribe(this);
    // 触发一次发布演示
    publisherM.doSomething();
    // connect(ui->pushButtonStart, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow()
{
    publisherM.unsubscribe(this);
    delete ui;
}

void MainWindow::onNotify(int eventId, void* data)
{
    QString msg = QString::fromStdString(data ? *(static_cast<std::string*>(data)) : "");
    QMessageBox::information(this, "Event Notification",
                             QString("Event ID: %1\nContent: %2").arg(eventId).arg(msg));
}

// void MainWindow::on_pushButton_clicked() {
//     // Example: Show a welcome message when clicking "Start Experience"
//     QMessageBox::information(this, "Info", "Welcome to use this application!");
// }
