#include "MousePointerManager.h"
#include "ImageProcessor.h"
#include <QWidget>
#include <QGraphicsScene>
#include <iostream>
#include <string>
#include <QGraphicsView>
#include "rocket.h"
extern Rocket *rocket;
using namespace std ;
MousePointerManager::MousePointerManager()
{
    socketMove.connectToHost("127.0.0.1",8888);
    socketClick.connectToHost("127.0.0.1",8889);
}

void MousePointerManager::mouseEvent(string event,int button)
{
    QString string;
    string.append(QString::fromStdString(event));
    string.append(",");
    string.append(QString::number(button));
    socketClick.write(string.toStdString().c_str());
}

void MousePointerManager::mouseMove(int x, int y)
{
    QCursor c;
    c.setPos(x,y+200);
    //c.shape();
    //setBackgroundBrush(QBrush(QImage(":/images/earth.jpg")));
    QString string;
    string.append(QString::number(x));
    string.append(",");
    string.append(QString::number(y));
    socketMove.write(string.toStdString().c_str());

}
