/*
  What
  Run another thread

  Why
  We have a powerful computer, lets use it

  How
  QObject::moveToThread
 */

#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QScopedPointer>
#include "task.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThread::currentThread()->setObjectName("Main thread");

    QThread worker;
    worker.setObjectName("Worker thread");
    QScopedPointer<Task> t(new Task());
    Task *task = t.data();
    task->moveToThread(&worker);

    worker.connect(&worker, &QThread::started, task, &Task::work);
    //Connect to QThread::finished if you need to know when the thread is done

    worker.start();
    qInfo() << "Free to do other things..." << QThread::currentThread();

    return a.exec();
}
