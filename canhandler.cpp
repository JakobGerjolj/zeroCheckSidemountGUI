#include "canhandler.h"
#include "qvariant.h"

canHandler::canHandler() {

    this -> startCAN();

}

canHandler::~canHandler(){

    canDevice -> disconnectDevice();
    delete canDevice;

}

void canHandler::startCAN(){

    const QString pluginName = "peakcan"; //clx000can

    canDevice = QCanBus::instance()->createDevice(pluginName, "usb0");

    QVariant bitrate = 250000;

    canDevice-> setConfigurationParameter(QCanBusDevice::BitRateKey, bitrate);
    canDevice -> BitRateKey;
    if (canDevice && canDevice->connectDevice()) {
        qDebug() << "Connected to CAN bus";
        connect(canDevice, &QCanBusDevice::framesReceived, this, &canHandler::readAndProcessCANpodatke);
    } else {
        qDebug() << "Failed to connect to CAN bus";
    }

}

void canHandler::readAndProcessCANpodatke()
{
    while (canDevice->framesAvailable()) {

        const QCanBusFrame frame = canDevice->readFrame();


        qDebug() << "Received a CAN package";
        qDebug() << "FRAME ID";
        qDebug() << frame.frameId();
        qDebug() << "FRAME ID_OVER";
        qDebug() << "Received a CAN package";

        if(frame.frameId() == 0x0CFF81FD){


            uint8_t rawByte1 = frame.payload()[2];
            uint8_t rawByte2 = frame.payload()[3];
        //if(frame.frameId() == 419404056){
            rawValue = (uint16_t)(rawByte1 | rawByte2 << 8);
            zeroValue = (uint8_t)frame.payload().at(4);

            qDebug() << "byte1: "<<static_cast<uint8_t>(frame.payload()[2]);
            qDebug() << "byte2: "<<static_cast<uint8_t>(frame.payload()[3]);

        }

    }
}

uint16_t canHandler::getRawValue(){

    return rawValue;

}
uint8_t canHandler::getZeroValue(){

    return zeroValue;

}
