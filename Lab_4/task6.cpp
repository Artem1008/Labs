#include "main.h"

int task6()
{
    int m;
    float fx;
    char cht;
    printf("Введите 3 числа через пробел int float char:\n");
    scanf("%d %f %c",&m,&fx,&cht);
    printf("Указатель: продемонстрировать использование операторов & и *:\n");
    int* pm=&m;
    float* pfx=&fx;
    char* pcht=&cht;
    printf("--------------------------------------------------------\n");
    printf("m = %d\n",*pm);
    printf("fx = %0.3f\n",*pfx);
    printf("cht = %c\n",*pcht);
    printf("Использование & оператор:\n");
    printf("--------------------------------------------------------\n");
    printf("адрес m = 0x%x\n",&m);
    printf("адрес fx = 0x%x\n",&fx);
    printf("адрес cht = 0x%x\n",&cht);
    printf("Используя операторы & и *:\n");
    printf("--------------------------------------------------------\n");
    printf("значение по адресу m = %d\n",*(&m));
    printf("значение по адресу fx = %0.3f\n",*pfx);
    printf("значение по адресу cht = %c\n",cht);
    printf("Используя только переменную указателя:\n");
    printf("--------------------------------------------------------\n");
    printf("адрес m = 0x%x\n",pm);
    printf("адрес fx = 0x%x\n",pfx);
    printf("адрес cht = 0x%x\n",pcht);
    printf("Использование только оператора указателя:\n");
    printf("--------------------------------------------------------\n");
    printf("значение по адресу m = %d\n",*pm);
    printf("значение по адресу fx = %0.3f\n",*pfx);
    printf("значение по адресу cht = %c\n",*pcht);
    int *Arr =new int[5]{5,7,2,9,8};
    for(int i=0;i<5;i++)
    {
        printf("Arr[%d]=0x%x, *Arr[%d]=%d \n",i,Arr,i,*Arr);
        Arr++;
    }
}
template<typename T>
int ChekValue(T &Value)
{
    int count=5;
    for(;count>=0;count--)
    {
        std::cin>>Value;
        std::cin.ignore(32767,'\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout<<"Вы ввели некоректное значение\n";
        }
        else return 1;
    }
    std::cout<<"Привышено число попыток ввода данных\n";
    return -1;
}
