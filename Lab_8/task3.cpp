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
    void addByte(int _value,std::string unit)
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

void ClearStringConsole(unsigned long long value,std::string str);
void task3()
{
    //если работаем с STL, то  будет на контейнерах
    //char units[][10]={"Gbyte","Мbyte","Kbyte","byte","MiB"};
    std::vector<std::string> units ={"byte","Kbyte","Мbyte","MiB","Gbyte"};
    auto itunits=units.begin();
    char c=0;
    Bytes value;
    printf("Введите число и стрелками вверх вниз выберите ед.изм.\n");
    while(c != 13)
    {
        c=getch();
        ClearStringConsole(value.getByte(*itunits),(*itunits));
        if (c == KEY_UP)
        {
            itunits=((itunits+1)==units.end())?units.begin():++itunits;
            printf("\r%lld %s",value.getByte(*itunits),(*itunits).c_str());
        }
        if (c == KEY_DOWN)
        {
            itunits=(itunits==units.begin())?--units.end():--itunits;
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
}
