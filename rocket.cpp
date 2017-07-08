#include "rocket.h"
#include "MousePointerManager.h"
#include <QTimer>
#include <QGraphicsScene>
extern MousePointerManager *hola;
Rocket::Rocket()
{
    setPixmap(QPixmap(":/images/rocket4.png"));
    QTimer *timer= new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(60);

}

void Rocket::setXpos(int x)
{
    this->xpos=x;
}

void Rocket::setYpos(int y)
{
    this->ypos=y;
}

void Rocket::move()
{
    setPos(this->xpos,this->ypos+200);
}
