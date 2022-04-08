#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QTimer>
#include <QDebug>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);

signals:


public slots:
    void timeout();

private:
    QTimer m_timer;
    int count;
};

#endif // TEST_H
