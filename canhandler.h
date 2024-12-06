#ifndef CANHANDLER_H
#define CANHANDLER_H

#include <QObject>
#include <QCanBusDevice>
#include <QCanBusDevice>
#include <QCanBus>
#include <QDebug>
#include <QTimer>
#include <QByteArray>
#include <QtEndian>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <cstdint>
#include <QByteArray>


class canHandler:  public QObject
{
    Q_OBJECT
public:
    canHandler();
    ~canHandler();
    uint16_t getRawValue();
    uint8_t getZeroValue();
private:
    uint16_t rawValue{0};
    uint8_t zeroValue{0};
    void readAndProcessCANpodatke();
    QCanBusDevice *canDevice;
    void startCAN();
};

#endif // CANHANDLER_H
