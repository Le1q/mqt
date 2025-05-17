#include "mainwindow.h"

#include <QMessageBox>
#include <QString>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    publisherM.subscribe(this);

    // Connect button signals to slots
    connect(ui->btnHome, &QPushButton::clicked, this, &MainWindow::onHomeButtonClicked);
    connect(ui->btnSettings, &QPushButton::clicked, this, &MainWindow::onSettingsButtonClicked);
    connect(ui->btnAbout, &QPushButton::clicked, this, &MainWindow::onAboutButtonClicked);

    // Set home page as default
    ui->mainStack->setCurrentIndex(0);
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

void MainWindow::onHomeButtonClicked()
{
    ui->mainStack->setCurrentIndex(0);
}

void MainWindow::onSettingsButtonClicked()
{
    ui->mainStack->setCurrentIndex(1);
}

void MainWindow::onAboutButtonClicked()
{
    ui->mainStack->setCurrentIndex(2);
}
