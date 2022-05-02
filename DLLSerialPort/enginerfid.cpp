#include "enginerfid.h"

EngineRfid::EngineRfid()
{
    pQSerialPortInfo = new QSerialPortInfo;
    pQSerialPort = new QSerialPort;
    connect(pQSerialPort,SIGNAL(readyRead()),this,SLOT(signalReceivedFromCard()));

    pQSerialPort->setPortName("com6");
    qDebug() << pQSerialPort->portName();
    pQSerialPort->setBaudRate(9600);
    pQSerialPort->setDataBits(QSerialPort::Data8);
    pQSerialPort->setParity(QSerialPort::NoParity);
    pQSerialPort->setStopBits(QSerialPort::OneStop);
    pQSerialPort->setFlowControl(QSerialPort::HardwareControl);
    pQSerialPort->open(QIODevice::ReadWrite);

}

EngineRfid::~EngineRfid()
{
    delete pQSerialPort;
    delete pQSerialPortInfo;
    pQSerialPort=nullptr;
    pQSerialPortInfo=nullptr;

}

void EngineRfid::restartRfid()
{
    pQSerialPort->open(QIODevice::ReadWrite);
}


void EngineRfid::signalReceivedFromCard()
{
    QByteArray koodi = pQSerialPort->readAll();
    koodi.remove(0,3);
    koodi.chop(3);
    pQSerialPort->close();
    id_card=koodi;
    emit cardReaded();
}

QString EngineRfid::getId_card() const
{
    return id_card;
}
