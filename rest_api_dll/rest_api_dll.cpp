#include "rest_api_dll.h"

Rest_api_dll::Rest_api_dll()
{
    objectApiEngine = new ApiEngine();
    connect (objectApiEngine, SIGNAL(httpResponseReady()), this, SLOT(httpReadyEngine()));
}

Rest_api_dll::~Rest_api_dll()
{
    delete objectApiEngine;
    objectApiEngine=nullptr;
}


void Rest_api_dll::interfaceHttpEvent(QString method, QString url, QByteArray webtoken, QJsonObject jsonObj)
{
    objectApiEngine->handleHttpRequest(method, url, webtoken, jsonObj);
}

QByteArray Rest_api_dll::interfaceReturnValue()
{
    return returnData;
}

void Rest_api_dll::httpReadyEngine()
{
    returnData=objectApiEngine->returnData();
    emit restApiReady();
}
