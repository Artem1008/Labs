#include <iostream>
#include "mytimer.h"

//������ ������� ��� ���
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
    printf("��� � ��४��稫� ����\n");
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
            std::cout<<"�� ����� ����४⭮� ���祭��\n";
        }
        else return 1;
    }
    std::cout<<"�ਢ�襭� �᫮ ����⮪ ����� ������\n";
    return -1;
}

int task2()
{
    //�᫮ ����祭�� ����⭮� � �ᮢ��
    int num1=7;
    //�᫮ ����祭�� ����⭮� � ᥪ㭤���
    int num2=39;
    //⠪ ��� � ��⪠� 2 ��࡫�� �
    printf("%d ࠧ� � ���� �� �� ��५�� �ᮢ ������뢠���� ��� �� ��㣠\n",(NOD(num1,num2)*24/8));
    MyTimer timer;
    int temphour;
    std::string answer;
    printf("������ �६� ��樨 � ���.\n");
    if(ChekValue(temphour)==-1) return -1;
    printf("�� �筮 ��� �������� �६� ��樨?(��/��� y/n.).\n");
    std::cin>>answer;
    if (answer=="��" || answer=="y")
    {
        int exit=3;
        while(exit)
        {
            timer.addUnits(temphour,TypeTime::second);
            timer.startTimers(SwitchPump);
            --exit;
        }
    }
    timer.delay(100);
    if (answer=="���" || answer=="n")  return 1;

    return 1;

}

