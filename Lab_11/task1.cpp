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
    printf("�६� %s\n",timer.print());
    timer.start();
    //����� �ਢ易�� ⠩��� ����� ��ᬠ�ਢ����� ����, c ���� ������, �� ����୮ ���� �� �����
    //timer.delay(10);
    timer.stop();
    printf("�६� ࠡ��� %.3f ᥪ.\n",timer.elapsed());
    printf("������ �६� ��� �������樨(��� ��室� ������ ������� esc ��� enter).\n");
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
    //���� ⠩��� � ⨯��
    timer.addUnits(6666,second);

    printf("\r%lld %s",timer.getUnits(),timer.getType());

    printf("\n");
    int day,month,year;
    printf("������ ���� �ଠ� 10.10.2024.\n");
    scanf("%d.%d.%d",&day,&month,&year);
    printf(timer.getDayOfWeek(day,month,year));
    return 1;

}
