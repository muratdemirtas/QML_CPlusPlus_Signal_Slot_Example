#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "deneme.h"
#include <QQuickWindow>
#include <QVariant>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    deneme x;
    qmlRegisterType<deneme>("com.murat.demo", 1, 0, "Deneme");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    QObject *topLevel = engine.rootObjects().value(0);

    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);

        // connect our QML signal to our C++ slot
    QObject::connect(window, SIGNAL(submitTextField(QString)),
                             &x, SLOT(receive(QString)));

        // connect our C++ signal to our QML slot
        // NOTE: if we want to pass an parameter to our QML slot, it has to be
        // a QVariant.
    QObject::connect(&x, SIGNAL(sendMessageToQML(QVariant)),
                             window, SLOT(setTextField(QVariant)));
    return app.exec();
}
