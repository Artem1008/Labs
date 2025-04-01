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
    Pool<Point> pp(5); 
    Point &p1 = pp.alloc(); 
    printf("p1 0x%x\n",&p1);    
    Point &p2 = pp.alloc(0, 1); 
    printf("p2 0x%x\n",&p2);
    Point &p3 = pp.alloc(2, 4); 
    printf("p3 0x%x\n",&p3);
    Point &p4 = pp.alloc(4, 5); 
    printf("p4 0x%x\n",&p4);
    Point &p5 = pp.alloc(6, 7);
    printf("p5 0x%x\n",&p5);
    pp.free(3);
    Point &p6 = pp.alloc(7, 8); 
    printf("p6 0x%x\n",&p6);
    pp.free();
    return 1;
}
