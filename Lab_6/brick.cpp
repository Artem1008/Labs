#include "brick.h"


void Brick::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setPen(Qt::DashDotDotLine);
    if (index==2) painter.setPen(myColor);
    painter.drawRect(100, 10, w, h);
    painter.setPen(Qt::black);
    painter.setPen(Qt::DashDotDotLine);
    painter.drawText(100+w/2-30, 10+h/2,"Сторона 2");
    if (index==3)
    {
        painter.setPen(myColor);
    }
    painter.drawRect(100, 10+h+20, w, l);
    painter.drawText(100+w/2-30, 10+h+20+l/2,"Сторона 3");
    painter.setPen(Qt::black);
    painter.setPen(Qt::DashDotDotLine);
    if (index==1)  painter.setPen(myColor);
    painter.drawRect(100+w+20, 10, l, h);
    painter.drawText(100+w+20+ l/2-30, 10+h/2,"Сторона 1");
    painter.setPen(Qt::black);
    painter.end();
}
Brick::Brick(QWidget *parent):QWidget(parent)
{

}

Brick::~Brick()
{

}
