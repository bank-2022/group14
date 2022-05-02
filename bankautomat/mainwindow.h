#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "login.h"
#include <dllserialport.h>

#include <QMainWindow>
#include <dllpincode.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnLogin_clicked();
    void waitForPinCode();
    void loginWithPinCode();
    void loginSlot();

    void on_btnRestart_clicked();

private:
    Ui::MainWindow *ui;
    Login *objectLogin;
    DLLSerialPort *objectSerialPort_dll;
    DLLPinCode *objectPinCode;
    QString idCard;
    QString pinCode;

    QString base_url;
    QByteArray token;
    Rest_api_dll *objectRest_api_dll;
    pankkiMain *objectpankkiMain;
signals:
    void pinCodeReceived();
};
#endif // MAINWINDOW_H
