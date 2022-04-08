#include <QCoreApplication>
#include "owner.h"
#include "dog.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    owner owner;
    dog dog;

    QObject::connect(&owner, &owner::treats, &dog, &dog::treats); //Auto

    // soomewhere else in the code
    for(int i=0; i<10; i++)
    {
        QObject::connect(&owner, &owner::treats, &dog, &dog::treats, Qt::UniqueConnection); //UniqueConnection
    }

    owner.giveSnacks();

    return a.exec();
}
