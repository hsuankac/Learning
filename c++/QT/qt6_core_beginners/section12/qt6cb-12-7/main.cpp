/*
    What
    Reinterpret cast
    Why
    Unlike static_cast, but like const_cast, the reinterpret_cast expression does not
    compile to any CPU instructions
    (except when converting between integers and pointers or on obscure
    architectures where pointer representation depends on its type).
    It is purely a compile-time directive which instructs the compiler
    to treat the expression as if it had the a new type.
    How
    See below
    Remember:
    The implicit cast is C++ doing it for us
    The explicit cast is us telling C++ what to do
    The static_cast operator performs a nonpolymorphic cast.
    The dynamic_cast operator ensures inheritence is good
    The reinterpret_cast operator types to convert it to a different type
*/

#include <QCoreApplication>
#include <QDebug>
#include "car.h"
#include "racecar.h"
#include "feline.h"

void testDrive(Car* obj)
{
    obj->drive();
    obj->stop();
}

void race(RaceCar* obj)
{
    obj->drive();
    obj->stop();
    obj->gofast();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

// For the reinterpret_cast
//    // Create a racecar
//    RaceCar* player1 = new RaceCar(&a);

//    // cast the racecar to the base
//    Car* obj = dynamic_cast<Car*>(player1);
//    if(obj) testDrive(obj);

//    // Cast it without changing it
//    RaceCar* speedstar = static_cast<RaceCar*>(obj);
//    if(speedstar) race(speedstar);

//    // Reinterpret it as a different type
//    int* pointer = reinterpret_cast<int*>(speedstar);
//    qInfo() << "Pointer" << pointer;
//    qInfo() << "Racecar" << speedstar;

//    RaceCar* mycar = reinterpret_cast<RaceCar*>(pointer);
//    qInfo() << "My Cars color is" << mycar->color;
//    race(mycar);

//    Feline* cat = reinterpret_cast<Feline*>(pointer);
//    cat->hiss();

// For the qobject_cast
    // Derived class to the base, just like dynamic_static
    RaceCar* mycar = new RaceCar(&a);
    Car* car = qobject_cast<Car*>(mycar);
    car->drive();

    // Base to the derived class, just like static_cast
    RaceCar* fastcar = qobject_cast<RaceCar*>(car);
    fastcar->gofast();

    return a.exec();
}
