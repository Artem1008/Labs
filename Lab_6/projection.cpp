#include "projection.h"

Projection::Projection(QWidget *parent):QWidget(parent)
{

}

void Projection::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.drawRect(10, 10, x, y);
    painter.end();
}
