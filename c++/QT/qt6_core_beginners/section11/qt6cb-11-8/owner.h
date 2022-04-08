#ifndef OWNER_H
#define OWNER_H

#include <QObject>
#include <QDebug>

class owner : public QObject
{
    Q_OBJECT
public:
    explicit owner(QObject *parent = nullptr);

    void giveSnacks();
signals:
    void treats();
};

#endif // OWNER_H
