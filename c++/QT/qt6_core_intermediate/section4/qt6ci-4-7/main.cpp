/*
  What
  QScopedPointer

  Why
  Manual memory management is error prone

  How
  See below
*/

#include <QCoreApplication>
#include <QScopedPointer>
#include "test.h"

void test()
{
    QScopedPointer<Test> sp(new Test());
    sp->setObjectName("My test");

    qInfo() << "Scopped Pointer" << &sp;
    qInfo() << "Pointer data" << sp.data();
    qInfo() << sp->objectName();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test();
    return a.exec();
}
