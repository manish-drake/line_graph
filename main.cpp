#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <linegraph.h>
#include <QQmlContext>
#include <client.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<LineGraph>("Graphs", 1, 0, "LineGraph");

    Client client;



    QQmlApplicationEngine engine;
    auto context = engine.rootContext();

    context->setContextProperty("client", &client);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
