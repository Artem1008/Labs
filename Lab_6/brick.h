#ifndef BRICK_H
#define BRICK_H
#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QMap>
#include "projection.h"

class Projection;
class Brick: public QWidget
{
    Q_OBJECT
private:
    int h=65;
    int l=120;
    int w=250;
    QColor myColor=Qt::green;
    int index;
    const QMap<int,QPair<int,int>> sizes
    {
        {1,{l,h}},
        {2,{w,h}},
        {3,{w, l}}
    };
protected:
    void paintEvent(QPaintEvent *event);
public:
    Brick(QWidget *parent = 0);
    friend int CheckGeometry(Projection &projection,Brick &brick);
    void Setindex(int _value) {index=_value;}
    ~Brick();
};

#endif // BRICK_H
