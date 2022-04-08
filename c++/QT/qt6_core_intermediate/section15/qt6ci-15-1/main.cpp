/*
  What
  Timers

  Why
  We want to wait without blocking execution

  How
  QTimer
  Example of single shot
 */

#include <QCoreApplication>
#include <QDebug>
#include <QTimer>

void test()
{
    qInfo() << "Thanks for waiting";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Please wait";
    QTimer::singleShot(5000, &test);

    return a.exec();
}
