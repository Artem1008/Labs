#include "main.h"
void task4()
{
    std::string str="AAAABCCCCCDDDDE";
    int countABC=0;
    char ABC;
    std::string rezult;
    for(int i=1;i<=(int)str.length();i++)
    {
        if ((str[i]==str[i-1]))
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
    printf("%s",rezult.c_str());
}
