#include "deneme.h"
#include <QDebug>

deneme::deneme(QObject *parent) : QObject(parent)
{

}



void deneme::receive(QString x)
{
    qDebug() << "QT C++:: received variable from QML Form: " << x;
    QVariant f = "Thanks From QT C++";
    emit sendMessageToQML(f);
}

