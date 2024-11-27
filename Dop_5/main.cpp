#include "main.h"

int main()
{
#if(TASK==1)
    std::cout<< "Задание 1:"<<'\n';
    task1();
#endif
#if(TASK==2)
    std::cout<< "Задание 2:"<<'\n';
    task2();
#endif
}
