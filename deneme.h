#ifndef DENEME_H
#define DENEME_H

#include <QObject>
#include <QVariant>

class deneme : public QObject
{
  Q_OBJECT

public:
    explicit deneme(QObject *parent = 0);
signals:
    void sendMessageToQML(QVariant g);
public slots:
    void receive(QString x);
};

#endif // DENEME_H
