#include "test.h"

test::test(QObject *parent) : QObject(parent)
{
    count = 0;
    connect(&m_timer, &QTimer::timeout, this, &test::timeout);
    m_timer.setInterval(1000);
    m_timer.start();
//    m_timer.stop();
}

void test::timeout()
{
    qInfo() << "Test!";
    count++;
    if(count>=3)
    {
        m_timer.stop();
        qInfo() << "Done!";
    }
}
