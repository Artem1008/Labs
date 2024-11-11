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
    printf("���ᨬ�: %u\n",operation(MAX,mass,sizeof(mass)/sizeof(*mass)));
    printf("������: %u",operation(MIN,mass,sizeof(mass)/sizeof(*mass)));
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
int operation(T(* op)(T[], int), T mass[], int size)
{
    return op(mass, size);
}
