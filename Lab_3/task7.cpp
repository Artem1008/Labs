#include "main.h"

void task7()
{
  Levels Level;

 while(true)
 {
   cout<<"������ �⠦ :";
   Level=(Levels)ChekValue();
    switch (Level)
    {
    case garage:
        std::cout<<"�� ���⨫��� � ��ࠦ\n";
        break;
    case hol:
        std::cout<<"�� � 宫��\n";
        break;
    case casino:
        std::cout<<"���� ��� � ������\n";
        break;
    case restaurant:
        std::cout<<"���⭮�� ����� � ���࠭�\n";
        break;
    case pool:
        std::cout<<"�� ���ᥨ��\n";
        break;
    case bar:
        std::cout<<"�� � ���\n";
        break;
    case cafe:
        std::cout<<"�� � ���\n";
        break;
    default:
        std::cout<<"������ �⠦� �� �������\n";
    }
 }
}

int ChekValue()
{
        int temp;
        cin>>temp;
        cin.ignore(32767,'\n');
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767,'\n');
            cout<<"�� ����� ����४⭮� ���祭��\n";
            return -1;
        }
    return temp;
}
