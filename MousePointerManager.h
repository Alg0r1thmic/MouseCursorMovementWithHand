#ifndef MOUSEPOINTERMANAGER_H
#define MOUSEPOINTERMANAGER_H
#include <QtNetwork/QTcpSocket>
#include <QObject>
#include <QGraphicsView>
#include <iostream>
using namespace std;
class MousePointerManager : public QObject
{
    Q_OBJECT
private:
    QTcpSocket socketMove;
    QTcpSocket socketClick;

public:
    MousePointerManager();
    void mouseEvent(string, int);
    void mouseMove(int, int);

};

#endif // MOUSEPOINTERMANAGER_H
