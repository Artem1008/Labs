#include "main.h"

std::string Pack(std::string str)
{
    std::string rezult;
    int countABC=0;
    for(int i=1;i<=(int)str.length();i++)
    {
        if (str[i]==str[i-1])
        {
            countABC++;
        }
        else
        {
            if(countABC>0)
            {
                rezult=rezult+IntToString(countABC+1);
                countABC=0;
            }
            rezult=rezult+str[i-1];
        }
    }
    return rezult;
}

std::string Unpack(std::string str)
{
    std::string rezult;
    std::string sCount;
    for(int i=0;i<(int)str.length();i++)
    {
        while (isdigit(str[i]))
        {
            sCount += str[i];
        }
        if(sCount!="")
        {
            for(int i=0;i<stod(sCount);i++)
            {
                rezult+=str[i];
            }
            sCount="";
        }
        else
        {
            rezult+=str[i];
        }
    }
    return rezult;
}
void task4()
{
    std::string str="AAAABCCCCCDDDDE";
    printf("Исходная строка: %s\n",str.c_str());
    printf("После упаковки: %s\n",Pack(str).c_str());
    printf("После распаковки: %s\n",Unpack(str).c_str());
}

