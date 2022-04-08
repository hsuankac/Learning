#include <QCoreApplication>
#include "source.h"
#include "destination.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Source oSource;
    Destination oDestination;
    QObject::connect(&oSource, &Source::mySignal, &oDestination, &Destination::mySignal);

    oSource.test();

    return a.exec();
}
