#ifndef REST_API_DLL_H
#define REST_API_DLL_H

#include "api_engine.h"
#include "rest_api_dll_global.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include <QObject>

class REST_API_DLL_EXPORT Rest_api_dll: public QObject
{
    Q_OBJECT
public:
    Rest_api_dll();
    ~Rest_api_dll();

    void interfaceHttpEvent(QString method, QString url, QByteArray webtoken, QJsonObject jsonObj={});
    QByteArray interfaceReturnValue();

private slots:
    void httpReadyEngine();

private:
    ApiEngine *objectApiEngine;
    QByteArray returnData;
signals:
    void restApiReady();

};

#endif // REST_API_DLL_H
