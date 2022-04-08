#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <iostream>
#include "radio.h"
#include "station.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    radio boombox;
    station* channels[3];

    // create some stations
    channels[0] = new station(&boombox, 94, "Rock and Roll");
    channels[1] = new station(&boombox, 87, "Hip Hop");
    channels[2] = new station(&boombox, 104, "News");

    boombox.connect(&boombox, &radio::quit, &a, &QCoreApplication::quit, Qt::QueuedConnection);

//    for(int i=0; i<3; i++)
//    {
//        station* channel = channels[i];
//        boombox.connect(channel, &station::send, &boombox, &radio::listen);
//    }

    do
    {
        qInfo() << "Enter on, off, test or quit";
        QTextStream qtin(stdin);
        QString line = qtin.readLine().trimmed().toUpper();

        if(line == "ON")
        {
            qInfo() << "Turn the radio on";
            for(int i=0; i<3; i++)
            {
                station* channel = channels[i];
                boombox.connect(channel, &station::send, &boombox, &radio::listen);
            }
            qInfo() << "Radio is on";
        }


        if(line == "OFF")
        {
            qInfo() << "Turn the radio off";
            for(int i=0; i<3; i++)
            {
                station* channel = channels[i];
                boombox.disconnect(channel, &station::send, &boombox, &radio::listen);
            }
            qInfo() << "Radio is off";
        }

        if(line == "TEST")
        {
            qInfo() << "Testing";
            for(int i=0; i<3; i++)
            {
                station* channel = channels[i];
                channel -> broadcast("Broadcasting live!");
            }
            qInfo() << "Test complete";
        }

        if(line == "QUIT")
        {
            qInfo() << "Quitting";
            emit boombox.quit();
            break;
        }

    } while(true);


    return a.exec();
}
