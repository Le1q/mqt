#pragma once
#include <QMainWindow>
#include "logic/code/pubsub_demo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Subscriber {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void onNotify(int eventId, void* data) override;
private:
    Ui::MainWindow *ui;
    MyPublisher publisherM;
private slots:
    // void on_pushButton_clicked();
};
