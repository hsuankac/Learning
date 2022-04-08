#include "racecar.h"

racecar::racecar(QObject *parent) : car(parent)
{

}

void racecar::gofast()
{
    qInfo() << "zooooooom";
}
