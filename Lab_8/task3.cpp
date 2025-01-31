#include <iostream>
#include <vector>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define BACKSPACE 8
void ClearStringConsole(int value,std::string str);
void task3()
{
    //если работает с STL будет на контейнерах
    //char units[][10]={"Gbyte","Мbyte","Kbyte","byte","MiB"};
    std::vector<std::string> units ={"Gbyte","Мbyte","Kbyte","byte","MiB"};
    std::vector<std::string>::iterator itunits=units.begin();
    char c=0;
    int value=0;
    printf("Введите число и стрелками вверх вниз выберите ед.изм.\n");
    while(c != 13)
    {
        c=getch();
        ClearStringConsole(value,(*itunits));
        if (c == KEY_UP)
        {
            if(itunits==units.end())
            {
                itunits=units.begin();
            }
            else
            {
                itunits++;
            }
            printf("\r%d %s",value,(*itunits).c_str());
        }
        if (c == KEY_DOWN)
        {
            if(itunits==units.begin()) itunits=units.end();
            else itunits--;
            printf("\r%d %s",value,(*itunits).c_str());
        }
        if((c>='0')&&c<='9')
        {
            value=value*10+(c-48);
            printf("\r%d %s",value,(*itunits).c_str());
        }
        if(c==BACKSPACE)
        {
            value/=10;
            printf("\r%d %s",value,(*itunits).c_str());
        }
    }
}
void ClearStringConsole(int value,std::string str)
{
    std::string temp;
    temp.push_back('\r');
    temp.push_back(' ');
    temp.push_back(' ');
    while((value/=10)>0)
    {
        temp.push_back(' ');
    }
    for(size_t i=0;i<str.size();i++)
    {
        temp.push_back(' ');
    }
    printf("%s",temp.c_str());
}
