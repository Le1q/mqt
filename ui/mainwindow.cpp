#include "mainwindow.h"

#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QPixmap>

#include "ui_mainwindow.h"
#include "logic/pill_counter.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    publisherM.subscribe(this);

    // Connect button signals to slots
    connect(ui->btnHome, &QPushButton::clicked, this, &MainWindow::onHomeButtonClicked);
    connect(ui->btnSettings, &QPushButton::clicked, this, &MainWindow::onSettingsButtonClicked);
    connect(ui->btnAbout, &QPushButton::clicked, this, &MainWindow::onAboutButtonClicked);
    connect(ui->openImageButton, &QPushButton::clicked, this, &MainWindow::onOpenImageButtonClicked);
    connect(ui->processImageButton, &QPushButton::clicked, this, &MainWindow::onProcessImageButtonClicked);

    // 设置处理按钮初始状态为禁用
    ui->processImageButton->setEnabled(false);
    
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

void MainWindow::onOpenImageButtonClicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "",
        tr("Image Files (*.png *.jpg *.bmp)"));
        
    if (fileName.isEmpty())
        return;
        
    currentImagePath = fileName;
    QPixmap pixmap(fileName);
    ui->imageLabel->setPixmap(pixmap.scaled(ui->imageLabel->size(), 
        Qt::KeepAspectRatio, Qt::SmoothTransformation));
    
    ui->processImageButton->setEnabled(true);
    ui->resultLabel->setText("Image loaded. Click 'Count Pills' to process.");
}

void MainWindow::onProcessImageButtonClicked()
{
    if (currentImagePath.isEmpty())
        return;
        
    try {
        auto result = PillCounter::countPills(currentImagePath.toStdString());
        
        // 显示处理后的图片
        QImage img(result.processedImage.data,
                  result.processedImage.cols,
                  result.processedImage.rows,
                  result.processedImage.step,
                  QImage::Format_BGR888);
                  
        ui->imageLabel->setPixmap(QPixmap::fromImage(img).scaled(
            ui->imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
            
        // 显示结果
        ui->resultLabel->setText(QString("Found %1 pills in the image.").arg(result.pillCount));
    }
    catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", QString("Error processing image: %1").arg(e.what()));
    }
}
