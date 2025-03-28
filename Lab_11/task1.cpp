#include "mytimer.h"

void ClearStringConsole(unsigned long long value,std::string str)
{
    std::string temp;
    temp.push_back('\r');
    temp.push_back(' ');
    temp.push_back(' ');
    while((value/=10)>0)
    {
        temp.push_back(' ');
    }
    temp.insert(3,str.size(),' ');
    printf("%s",temp.c_str());
};

int task1()
{
    MyTimer timer;
    printf("время %s\n",timer.print());
    timer.start();
    //можно привязать таймер который рассматривается ниже, c ручным вводом, но наверно пока не важно
    //timer.delay(10);
    timer.stop();
    printf("время работы %.3f сек.\n",timer.elapsed());
    printf("Введите время для конвертации(для выхода нажмити клавишу esc или enter).\n");
    char c=0;
    while((c != ENTER) &&(c != ESC) )
    {
        c=getch();
        ClearStringConsole(timer.getUnits(),timer.getType());
        if (c == KEY_UP)
        {
            ++timer;
            printf("\r%lld %s",timer.getUnits(),timer.getType());
        }
        if (c == KEY_DOWN)
        {
            --timer;
            printf("\r%lld %s",timer.getUnits(),timer.getType());
        }
        if((c>='0')&&c<='9')
        {
            timer.addUnits(c);
            printf("\r%lld %s",timer.getUnits(),timer.getType());
        }
        if(c==BACKSPACE)
        {
            if (timer.getUnits()>0) timer.subUnits();
            printf("\r%lld %s",timer.getUnits(),timer.getType());
        }
    }
    //ввод таймера с типом
    timer.addUnits(6666,second);

    printf("\r%lld %s",timer.getUnits(),timer.getType());

    printf("\n");
    int day,month,year;
    printf("Введите дату формата 10.10.2024.\n");
    scanf("%d.%d.%d",&day,&month,&year);
    printf(timer.getDayOfWeek(day,month,year));
    return 1;

}
