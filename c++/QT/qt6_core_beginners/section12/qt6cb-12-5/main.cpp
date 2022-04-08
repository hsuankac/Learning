#include <QCoreApplication>
#include <QDebug>
#include "car.h"
#include "racecar.h"
#include "feline.h"

// Dynamic cast
// dynamic_cast can be used only with pointers and references to objects
// It purpose is to ensure that the result of the type conversion is a valid complete object of the requested class

void testDrive(car* obj)
{
    obj->drive();
    obj->stop();
}

void race(racecar* obj)
{
    obj->drive();
    obj->stop();
    obj->gofast();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    racecar* player1 = new racecar(&a);
    testDrive(player1); //Implicit conversion

    // correct way
    car* obj = dynamic_cast<car*>(player1); // Explicitly convert
    if(obj) testDrive(obj);

    feline* cat = new feline(&a);
    car* catcar = dynamic_cast<car*>(cat);
    if(catcar) testDrive(catcar);


    return a.exec();
}
