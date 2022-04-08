#include "owner.h"

owner::owner(QObject *parent) : QObject(parent)
{

}

void owner::giveSnacks()
{
    qInfo() << "Snacks are ready";
    emit treats();
}
