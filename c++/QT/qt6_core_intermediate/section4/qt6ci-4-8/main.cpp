/*
  What
  QSharedPointer

  Why
  Manual memory management is error prone

  How
  See below
*/

#include <QCoreApplication>
#include <QSharedPointer>
#include "test.h"

QSharedPointer<Test> getObject(QString name)
{
    QSharedPointer<Test> sp(new Test());
    sp->setObjectName(name);
     qInfo() << "SharedPointer in getObject function" << &sp;
    // Do other things here
    return sp;
}

void doWork(QSharedPointer<Test> sp)
{
    //We are using a copy of tyhe sharedpointer
    qInfo() << "Work" << sp.data();
    qInfo() << "sharedpointer" << &sp;
}

void test()
{
    qInfo() << "Getting the object";
    QSharedPointer<Test> ptr = getObject("My object");
    qInfo() << "SharedPointer" << &ptr;
    qInfo() << "obj" << ptr.data();

    doWork(ptr);

    //Reference count is zero
    qInfo() << "Complete";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test();

    return a.exec();
}
