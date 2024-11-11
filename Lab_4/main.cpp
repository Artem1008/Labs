#include "main.h"

int main()
{
#if (TASK==1)
    std::cout<< "Задание 1:"<<'\n';
    task1();
#endif

#if (TASK==2)
    std::cout<< "Задание 2:"<<'\n';
    task2();
#endif
#if (TASK==3)
    std::cout<< "Задание 3:"<<'\n';
    task3();
#endif
#if(TASK==4)
    std::cout<< "Задание 4:"<<'\n';
    task4();
#endif
#if(TASK==5)
    std::cout<< "Задание 5:"<<'\n';
    task5();
#endif
#if(TASK==6)
    std::cout<< "Задание 6:"<<'\n';
    task6();
#endif
#if(TASK==7)
    std::cout<< "Задание 7:"<<'\n';
    task7();
#endif
}

