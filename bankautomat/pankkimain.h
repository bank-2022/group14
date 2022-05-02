#ifndef PANKKIMAIN_H
#define PANKKIMAIN_H

#include "myurl.h"

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <rest_api_dll.h>

namespace Ui {
class pankkiMain;
}

class pankkiMain : public QDialog
{
    Q_OBJECT

public:
    explicit pankkiMain(QString stuUsername,QByteArray token, QWidget *parent = nullptr);
    ~pankkiMain();

private slots:
    void on_saldoButton_clicked();
    void saldoSlot();

    void on_tilitapahtumatbtn_clicked();
    void tilitapahtumatSlot();

    void on_pushButton_clicked();

private:
    Ui::pankkiMain *ui;
    QString saldo;
    QByteArray response_data;
    QString username;
    QByteArray webtoken;
    Rest_api_dll *objectRest_api_dll;
};

#endif // PANKKIMAIN_H
