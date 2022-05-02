#include "api_engine.h"


ApiEngine::ApiEngine()
{

}

ApiEngine::~ApiEngine()
{

}

void ApiEngine::handleHttpRequest(QString method, QString url, QByteArray webtoken, QJsonObject jsonObj)
{
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webtoken));
    //WEBTOKEN LOPPU

    httpManager = new QNetworkAccessManager(this);

    connect(httpManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(handleHttpResponse(QNetworkReply*)));

    if(method=="get"){
        reply = httpManager->get(request);
    }
    else if(method=="post"){
        reply = httpManager->post(request, QJsonDocument(jsonObj).toJson());
    }
    else if(method=="put"){
        reply = httpManager->put(request, QJsonDocument(jsonObj).toJson());
    }
    else if(method=="delete"){
        reply = httpManager->deleteResource(request);
    }
}

void ApiEngine::handleHttpResponse(QNetworkReply *reply)
{
    response_data=reply->readAll();
    reply->deleteLater();
    httpManager->deleteLater();
    emit httpResponseReady();
}

QByteArray ApiEngine::returnData()
{
    qDebug()<<"Engine data : "+response_data;
    //QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    return response_data;
}
