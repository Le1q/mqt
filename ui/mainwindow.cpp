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
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow()
{
    publisherM.unsubscribe(this);
    delete ui;
}

void MainWindow::onNotify(int eventId, void* data)
{
    QString msg = QString::fromStdString(data ? *(static_cast<std::string*>(data)) : "");
    QMessageBox::information(this, "事件通知",
                             QString("事件ID: %1\n内容: %2").arg(eventId).arg(msg));
}

void MainWindow::on_pushButton_clicked()
{
    // TODO: 实现按钮点击后的逻辑
    publisherM.doSomething();
}
