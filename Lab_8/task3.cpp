#include <iostream>
#include <vector>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
void task3()
{
    //если работает с STL будет на контейнерах
    //char units[][10]={"Gbyte","Мbyte","Kbyte","byte","MiB"};
    std::vector<std::string> units ={"Gbyte","Мbyte","Kbyte","byte","MiB"};
    std::vector<std::string>::iterator itunits=units.begin();
    char c=0;
    int value=0;
    while(c != 13)
    {
        c=getch();

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
            system("cls");
            printf("%d %s",value,(*itunits).c_str());
        }
        if (c == KEY_DOWN)
        {
            if(itunits==units.begin()) itunits=units.end();
            else itunits--;
            system("cls");
           printf("%d %s",value,(*itunits).c_str());
        }
        else if((c>=48)&&c<=57)
        {
            value=value*10+(c-48);
             system("cls");
             printf("%d",value);
        }
    }
}
