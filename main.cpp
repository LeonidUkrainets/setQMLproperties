#include <QQmlComponent>                // потрібен для управління компонентами форми
#include <QGuiApplication>
#include <QQmlEngine>                   // потрібен для рушія
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    // під'єднання до форми
    QQmlEngine      engine;
    QQmlComponent   component(&engine, QUrl::fromLocalFile("c:\\Qt\\ProjectsQT\\project18properties\\Main.qml") );
    QObject         *object = component.create();
    // Зміна властивостей
    object->setProperty("width",  888);
    object->setProperty("height", 888);
    object->setProperty("title", "Властивості змінені");
    object->setProperty("x", 111);
    object->setProperty("y", 111);
    // Зміна властивостей внутрішнього компонента
    QObject         *rectangle = object->findChild<QObject*>("rectangle");
    if (rectangle!=nullptr)
    {
        rectangle->setProperty("color", "yellow");
    }
    qDebug()<<"Початкове значення логічної змінної"<<object->property("someBool");
    qDebug()<<"Початкове значення цілочисельної змінної"<<object->property("someInt");
    object->setProperty("someBool", true);
    object->setProperty("someInt", 111);
    qDebug()<<"Змінене значення логічної змінної"<<object->property("someBool");
    qDebug()<<"Змінене значення цілочисельної змінної"<<object->property("someInt");
    if (object->property("someBool")==true)
    {
        rectangle->setProperty("visible", "false");
    };
    return app.exec();
}
