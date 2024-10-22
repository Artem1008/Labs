#include "main.h"

void task7()
{
  Levels Level;

 while(true)
 {
   cout<<"Введите этаж :";
   Level=(Levels)ChekValue();
    switch (Level)
    {
    case garage:
        std::cout<<"Вы спустились в гараж\n";
        break;
    case hol:
        std::cout<<"Вы в холле\n";
        break;
    case casino:
        std::cout<<"Удачи вам в казино\n";
        break;
    case restaurant:
        std::cout<<"Приятного апетита в ресторане\n";
        break;
    case pool:
        std::cout<<"Вы бассеине\n";
        break;
    case bar:
        std::cout<<"Вы в баре\n";
        break;
    case cafe:
        std::cout<<"Вы в кафе\n";
        break;
    default:
        std::cout<<"Такого этажа не существует\n";
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
            cout<<"Вы ввели некоректное значение\n";
            return -1;
        }
    return temp;
}
