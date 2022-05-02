#ifndef ENGINERFID_H
#define ENGINERFID_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QByteArray>

class EngineRfid : public QObject
{
    Q_OBJECT
public:
    EngineRfid();
    ~EngineRfid();
    void restartRfid();

    QString getId_card() const;

public slots:
    void signalReceivedFromCard();

signals:
    void cardReaded();

private:
    QSerialPort *pQSerialPort;
    QSerialPortInfo *pQSerialPortInfo;
    QString id_card;
};

#endif // ENGINERFID_H
