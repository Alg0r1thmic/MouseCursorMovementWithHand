#ifndef ROCKET_H
#define ROCKET_H
#include <QGraphicsPixmapItem>
#include <QObject>
class Rocket:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Rocket();
    void setXpos(int);
    void setYpos(int);
private:
    int xpos;
    int ypos;
public slots:
    void move();

};

#endif // ROCKET_H
