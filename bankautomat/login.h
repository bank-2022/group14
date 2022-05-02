#ifndef LOGIN_H
#define LOGIN_H

#include "myurl.h"
#include "pankkimain.h"

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_btnLogin_clicked();
    void loginSlot();

private:
    Ui::Login *ui;
    QString username;
    QString password;
    pankkiMain *objectpankkiMain;

    QString base_url;

    QByteArray token;

    Rest_api_dll *objectRest_api_dll;


};

#endif // LOGIN_H
