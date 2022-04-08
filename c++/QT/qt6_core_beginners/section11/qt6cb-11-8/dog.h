#ifndef DOG_H
#define DOG_H

#include <QObject>
#include <QDebug>

class dog : public QObject
{
    Q_OBJECT
public:
    explicit dog(QObject *parent = nullptr);

signals:

public slots:
    void treats();
};

#endif // DOG_H
