#ifndef DLLSERIALPORT_H
#define DLLSERIALPORT_H

#include "DLLSerialPort_global.h"
#include <QObject>
#include "enginerfid.h"

class DLLSERIALPORT_EXPORT DLLSerialPort :public QObject
{
    Q_OBJECT
public:
    DLLSerialPort(QObject * parent = nullptr);
    ~DLLSerialPort();

    QString interfaceReturnValue();
    void restartSerialReading();

private slots:
    void serialReadingReady();
signals:

    void dllSerialPortReady();


private:
    EngineRfid *objectEngine;
    QString returnData;
};

#endif // DLLSERIALPORT_H
