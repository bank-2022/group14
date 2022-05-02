#include "dllserialport.h"

DLLSerialPort::DLLSerialPort(QObject *parent):QObject(parent)
{
    qDebug()<<"SERIAL DLL object";
    objectEngine = new EngineRfid;
    connect(objectEngine, SIGNAL(cardReaded()), this, SLOT(serialReadingReady()));
}

DLLSerialPort::~DLLSerialPort()
{
    delete objectEngine;
    objectEngine=nullptr;
}

QString DLLSerialPort::interfaceReturnValue()
{
    return returnData;
}

void DLLSerialPort::restartSerialReading()
{
    objectEngine->restartRfid();
}

void DLLSerialPort::serialReadingReady()
{
    returnData=objectEngine->getId_card();
    emit dllSerialPortReady();
}

