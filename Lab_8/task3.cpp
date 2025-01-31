#include <iostream>
#include <vector>
#include <map>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define BACKSPACE 8

class Bytes
{
private:
    std::map<std::string,unsigned int> tableConvert;
    unsigned long long value;
public:
    Bytes():value(0)
    {
        tableConvert.insert(std::make_pair("byte", 1));
        tableConvert.insert(std::make_pair("Kbyte", 1024));
        tableConvert.insert(std::make_pair("MiB", 1048576));
        tableConvert.insert(std::make_pair("Мbyte", 1048576));
        tableConvert.insert(std::make_pair("Gbyte", 1073741824));
    }
    void addByte(unsigned long long _value,std::string unit)
    {

        value= ((value/tableConvert[unit])*10+_value)*tableConvert[unit];
    }
    void subByte(std::string unit)
    {
        value=((value/tableConvert[unit])/10)*tableConvert[unit];
    }
    unsigned long long getByte(std::string unit)
    {
        return value/tableConvert[unit];
    }

};

void ClearStringConsole(int value,std::string str);
void task3()
{
    //если работает с STL будет на контейнерах
    //char units[][10]={"Gbyte","Мbyte","Kbyte","byte","MiB"};
    std::vector<std::string> units ={"byte","Kbyte","Мbyte","MiB","Gbyte"};
    std::vector<std::string>::iterator itunits=units.begin();
    char c=0;
    Bytes value;
    printf("Введите число и стрелками вверх вниз выберите ед.изм.\n");
    while(c != 13)
    {
        c=getch();
        ClearStringConsole(value.getByte(*itunits),(*itunits));
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
           printf("\r%lld %s",value.getByte(*itunits),(*itunits).c_str());
        }
        if (c == KEY_DOWN)
        {
            if(itunits==units.begin()) itunits=units.end();
            else itunits--;
            printf("\r%lld %s",value.getByte(*itunits),(*itunits).c_str());
        }
        if((c>='0')&&c<='9')
        {
            value.addByte((c-48),*itunits);
            printf("\r%lld %s",value.getByte(*itunits),(*itunits).c_str());
        }
        if(c==BACKSPACE)
        {
            if (value.getByte(*itunits)>0) value.subByte(*itunits);
           printf("\r%lld %s",value.getByte(*itunits),(*itunits).c_str());
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
