#include "pool.h"

class Point {
    int m_x, m_y;
public:
    Point() // ��������� ��� ��ࠬ��஢
        : m_x(0), m_y(0){}
    Point(int x, int y) // ��������� � ��ࠬ��ࠬ�
        : m_x(x), m_y(y){}
    ~Point()
    {
        printf("�������� 0x%x\n",this);
    }
};

int task5()
{
    Pool<Point> pp(10); // �뤥���� ������ ��� 10 ��ꥪ⮢ Point
    Point &p1 = pp.alloc(); // �ࠡ�⠫ ��������� Point()
    printf("p1 0x%x\n",&p1);
    Point &p2 = pp.alloc(0, 1); // �ࠡ�⠫ ��������� Point(0, 1)
    printf("p2 0x%x\n",&p2);
    return 1;
}
