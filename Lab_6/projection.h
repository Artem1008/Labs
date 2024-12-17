#ifndef PROJECTION_H
#define PROJECTION_H
#include <QWidget>
#include <QPainter>
#include <QDebug>
#include "brick.h"
class Brick;
class Projection: public QWidget
{
     Q_OBJECT

private:
       int x=10,y=10;
public:
    Projection(QWidget *parent = 0);
    void SetX(int _value){x=_value;}
    void SetY(int _value){y=_value;}
     friend int CheckGeometry(Projection &projection, Brick &brick);
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // PROJECTION_H
