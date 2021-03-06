/*
  What
  Make a simple app that saves settings

  Why
  Practice what you have learned

  How
  Ask for their name and read it back to them
 */


#include <QCoreApplication>
#include <QDebug>
#include <QSettings>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Kai");
    QCoreApplication::setOrganizationDomain("Kai.com");
    QCoreApplication::setApplicationName("Kai Chang");

    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    if(settings.contains("name"))
    {
        qInfo() << "Hello" << settings.value("name").toString();
        settings.sync();
    }
    else
    {
        QTextStream qin(stdin);
        qInfo() << "Enter your name:";
        QString name = qin.readLine();
        settings.setValue("name", name);
        qInfo() << "Close the application and en-open it";
    }

    return a.exec();
}
