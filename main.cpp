#include <QApplication>
#include <QtQml> // for qmlRegisterType
#include <QQmlApplicationEngine>

#include "ccpuinfo.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // register C++ class for QML to use
    qmlRegisterType<CCpuInfo>("CpuInfo", 1, 0, "CCpuInfo");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
