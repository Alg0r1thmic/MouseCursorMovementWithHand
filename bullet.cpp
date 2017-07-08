#include "bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
Bullet::Bullet()
{
    setPixmap(QPixmap(":/images/Missle.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);
    setPos(x()+100,y());
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(30);
    //Qtimer *timer = new QTimer();
}

void Bullet::move()
{
    setPos(x(),y()+5);
    if(pos().y()<0 || pos().y()>600)
    {
        scene()->removeItem(this);
        delete this;
        //qDebug()  << "remove bullet";
    }
}
