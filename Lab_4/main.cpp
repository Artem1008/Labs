#include "main.h"

int main()
{
#if (TASK==1)
    std::cout<< "������� 1:"<<'\n';
    task1();
#endif

#if (TASK==2)
    std::cout<< "������� 2:"<<'\n';
    task2();
#endif
#if (TASK==3)
    std::cout<< "������� 3:"<<'\n';
    task3();
#endif
#if(TASK==4)
    std::cout<< "������� 4:"<<'\n';
    task4();
#endif
#if(TASK==5)
    std::cout<< "������� 5:"<<'\n';
    task5();
#endif
#if(TASK==6)
    std::cout<< "������� 6:"<<'\n';
    task6();
#endif
#if(TASK==7)
    std::cout<< "������� 7:"<<'\n';
    task7();
#endif
}

