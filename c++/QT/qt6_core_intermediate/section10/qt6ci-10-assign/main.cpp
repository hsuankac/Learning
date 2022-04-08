/*
  What
  Encode and decode base64

  Why
  Practice what you have learned

  How
  QByteArray
 */


#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString data = "Hello my name is Kai";
    QByteArray encoded = data.toLatin1().toBase64();
    QByteArray decoded = QByteArray::fromBase64(encoded);

    qInfo() << "Encoded: " << encoded;
    qInfo() << "------------------------";
    qInfo() << "Decoded: " << decoded;

    return a.exec();
}
