#ifndef API_ENGINE_H
#define API_ENGINE_H

#include <QString>
#include <QObject>
#include <QDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class ApiEngine : public QObject
{
    Q_OBJECT
public:
    ApiEngine();
    ~ApiEngine();
    QByteArray returnData();
    void handleHttpRequest(QString method, QString url, QByteArray webtoken, QJsonObject jsonObj={});

private slots:
    void handleHttpResponse(QNetworkReply *reply);

private:
    QNetworkAccessManager *httpManager;
    QNetworkReply *reply;
    QByteArray response_data;


signals:
    void httpResponseReady();
};

#endif // API_ENGINE_H

