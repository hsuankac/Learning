/*
  What
  Thread Pools

  Why
  We want to run more than one thread
  AND WE WANT IT NOW

  How
  QThreadPool
 */

#include <QCoreApplication>
#include <QDebug>
#include <QThreadPool>
#include <QThread>
#include "task.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThread::currentThread()->setObjectName("Main Thread");
    qInfo() << "Starting work" << QThread::currentThread();

    qInfo() << "Maximum Threads"<< QThreadPool::globalInstance()->maxThreadCount();

    for(int i = 0; i < 50; i++)
    {
        Task *task = new Task();
        task->setAutoDelete(true);
        QThreadPool::globalInstance()->start(task);
    }

    qInfo() << "Finished work" << QThread::currentThread();
    return a.exec();
}
