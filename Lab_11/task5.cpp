#include "pool.h"

class Point {
    int m_x, m_y;
public:
    Point() // конструктор без параметров
        : m_x(0), m_y(0){}
    Point(int x, int y) // конструктор с параметрами
        : m_x(x), m_y(y){}
    ~Point()
    {
        printf("деструктор 0x%x\n",this);
    }
};

int task5()
{
    Pool<Point> pp(10); // выделена память под 10 объектов Point
    Point &p1 = pp.alloc(); // сработал конструктор Point()
    printf("p1 0x%x\n",&p1);
    Point &p2 = pp.alloc(0, 1); // сработал конструктор Point(0, 1)
    printf("p2 0x%x\n",&p2);
    return 1;
}
