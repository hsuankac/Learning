/*
  What
  QIODevice
  Why
  QIODevice is the base class of all IO devices
  How
  QBuffer which is a simple IO Device
 */

#include <QCoreApplication>
#include <QDebug>
#include <QIODevice>
#include <QBuffer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QBuffer buffer;
    if(buffer.open(QIODevice::ReadWrite))
    {
        qInfo() << "Device is open";
        QByteArray data("Hell World");
        for(int i = 0; i < 5; i++)
        {
            buffer.write(data);
            buffer.write("\r\n");
        }

        buffer.seek(0);
        qInfo() << buffer.readAll();
        qInfo() << "Closing buffer";
        buffer.close();
    }
    else
    {
        qInfo() << "Could not open the device";
    }

    qInfo() << "Finished";

    return a.exec();
}
