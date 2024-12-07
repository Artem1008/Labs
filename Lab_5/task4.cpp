#include "main.h"
#include <cstring>

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
           rezult+= std::tolower(str[i-1]);
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
        if (isdigit(str[i]))
        {
            sCount += str[i];
            continue;
        }
        if(sCount!="")
        {
            for(int j=0;j<stod(sCount);j++)
            {
                rezult+=std::toupper(str[i]);
            }
            sCount="";
        }
        else
        {
            rezult+=std::toupper(str[i]);
        }
    }
    return rezult;
}
void task4()
{
    std::string str="AAAABCCCCCDDDDE";
    printf("Исходная строка: %s\n",str.c_str());
    std::string strpack=Pack(str);
    printf("После упаковки: %s\n",strpack.c_str());
    std::string strunpack=Unpack(strpack);
    printf("После распаковки: %s\n",strunpack.c_str());
}
