#include <iostream>
#include "mytimer.h"

//Алгоритм Евклида для НОД
int NOD(int num1,int num2)
{
    while (num1 != 0 && num2 != 0)
    {
        if (num1>=num2) num1=num1%num2;
        else num2=num2%num1;
    }
    return(num1+num2);
}
void SwitchPump()
{
    printf("\n");
    printf("как то переключили насос\n");
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

int task2()
{
    //число пересечений минутной и часовой
    int num1=7;
    //число пересечений минутной и секундной
    int num2=39;
    //так как в сутках 2 циферблата то
    printf("%d раза в день все три стрелки часов накладываются друг на друга\n",(NOD(num1,num2)*24/8));
    MyTimer timer;
    int temphour;
    std::string answer;
    printf("Введите время ротации в часах.\n");
    if(ChekValue(temphour)==-1) return -1;
    printf("Вы точно хотите изменить время ротации?(да/нет y/n.).\n");
    std::cin>>answer;
    if (answer=="да" || answer=="y")
    {
        int exit=3;
        while(exit)
        {
            timer.addUnits(temphour,TypeTime::second);
            timer.startTimers(SwitchPump);
            --exit;
        }
    }
    if (answer=="нет" || answer=="n")  return 1;

    return 1;

}

