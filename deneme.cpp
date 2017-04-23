#include "deneme.h"  //include header of deneme class
#include <QDebug>    //include for qdebug function

//create  class constructor
deneme::deneme(QObject *parent) : QObject(parent)
{

}


//this function will receive text from qml form and send response to qml from this class
void deneme::receive(QString x)
{
    //notify us...
    qDebug() << "QT C++:: received variable from QML Form: " << x;
    //create response packets
    QVariant f = "Thanks From QT C++";
    emit sendMessageToQML(f);   //emit signal for qml
}

