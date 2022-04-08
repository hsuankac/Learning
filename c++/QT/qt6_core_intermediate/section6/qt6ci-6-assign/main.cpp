#include <QCoreApplication>
#include <person.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Person p(nullptr, "Kai", "Chang");
    qInfo() << p.display().toString();

    return a.exec();
}
