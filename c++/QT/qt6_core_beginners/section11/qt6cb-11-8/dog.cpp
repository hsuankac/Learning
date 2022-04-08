#include "dog.h"

dog::dog(QObject *parent) : QObject(parent)
{

}

void dog::treats()
{
    qInfo() << "BARK";
}
