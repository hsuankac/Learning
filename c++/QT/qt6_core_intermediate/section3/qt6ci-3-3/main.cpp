/*
    What
    Signals and slots
    Why
    Easy communication between QObjects
    How
    Two objects talking
*/

#include <QCoreApplication>
#include "test.h"

void notifications()
{
    Test mom;
    Test child;

    mom.setObjectName("Mom");
    child.setObjectName("Child");

    QObject::connect(&mom, &Test::alarm, &child, &Test::wake, Qt::ConnectionType::AutoConnection);
//    mom.testing();
    child.wake("Now");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    notifications();
    return a.exec();
}
