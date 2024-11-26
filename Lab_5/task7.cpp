#include "main.h"

void task7()
{
    std::string str="72456273";
    int a1=StringToInt(str);
    printf("%d\n",a1);
    str=IntToString(a1);
    printf("%s",str.c_str());
}
std::string IntToString(int a1)
{
    std::string result;
    while(a1>0)
    {
        result=(char)(a1%10+0x30)+result;
        a1=a1/10;
    }
    return result;
}
int StringToInt(std::string str)
{
    int rezult=0;
    for(char v:str)
    {
        if((v>=0x30)&&(v<=0x39))
        {
            rezult=rezult*10+(v-0x30);
        }
        else
        {
            printf("Ошибка в веденной строке");
            exit(-1);
        }
    }
    return rezult;
}
