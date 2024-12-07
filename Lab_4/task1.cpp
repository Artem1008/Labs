#include "main.h"

void task1()
{
    std::random_device rd;
    std::mt19937 mersenne(rd());
    unsigned int mass[10];
    for(auto &var:mass)
    {
        std::cout<<(var=mersenne())<<'\n';
    }
    printf("Максимум: %u\n",(unsigned int)operation(MAX,mass,sizeof(mass)/sizeof(*mass)));
    printf("Минимум: %u",(unsigned int)operation(MIN,mass,sizeof(mass)/sizeof(*mass)));
}


template<typename T>
T SeekMin(T mass[] ,int size)
{
    T rezult=*mass;
    for(int i=1;i<size;i++)
    {
        rezult= (rezult<mass[i])?rezult:mass[i];
    }
    return rezult;
}

template<typename T>
T SeekMax(T mass[] ,int size)
{
    T rezult=*mass;
    for(int i=1;i<size;i++)
    {
        rezult= (rezult>mass[i])?rezult:mass[i];
    }
    return rezult;
}

template<typename T>
T operation(T(* op)(T[], int), T mass[], int size)
{
    return op(mass, size);
}

