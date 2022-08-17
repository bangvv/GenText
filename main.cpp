#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QByteArray>
#include <QStringList>
#include <QTextStream>


int main()
{
    QFile f("TEXT_IN.txt");
    f.open(QIODevice::ReadWrite);
    QByteArray b = f.readAll();
    f.close();

    QString buff(b);
    QString text;
    int n = 0;
    buff.replace(".","");
    buff.replace(",","");
    QStringList list = buff.split(" ",QString::SplitBehavior::SkipEmptyParts);
    QStringList listnew;
    for(int i = 0; i < list.size(); i++)
    {
        text = list.at(i);
        n = text.length();
        {
            listnew.append("hoắc " + text + " k" + "\n");
        }
    }

    QFile f1("TEXT_OUT.txt");
    f1.open(QIODevice::ReadWrite);
    QTextStream o(&f1);
    for(int i = 0; i < listnew.size(); i++){
        o.setCodec("UTF-8");
        o << listnew.at(i);
    }

    f1.close();

    return 0;
}
