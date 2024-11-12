#include "main.h"


int task8()
{
    int Operator;
    printf("Введите тип массива:\n");
    printf("1. И\n");
    printf("2. ИЛИ\n");
    printf("3. XOR\n");
    printf("9. Выход\n");
    if(ChekValue(Operator)==-1) return -1;
    int a1,a2;
    printf("Введите 2 числа через пробел:\n");
    scanf("%d %d",&a1,&a2);
    switch(Operator)
    {
    case 1:
        printf("%d",LogicOperation(AND,a1,a2));
        break;
    case 2:
         printf("%d",LogicOperation(OR,a1,a2));
        break;
    case 3:
         printf("%d",LogicOperation(XOR,a1,a2));
        break;
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
int AND(int a1 ,int a2)
{
    return (a1&a2);
}
int OR(int a1 ,int a2)
{
    return (a1|a2);
}
int XOR(int a1 ,int a2)
{
    return (a1^a2);
}
int LogicOperation(std::function<int(int,int)> pfcn,int a1, int a2)
{
    return pfcn(a1, a2);
}
