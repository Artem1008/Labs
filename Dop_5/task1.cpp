#include "main.h"

const uint32_t pow10Table32[]=
{
    1000000000ul,
    100000000ul,
    10000000ul,
    1000000ul,
    100000ul,
    10000ul,
    1000ul,
    100ul,
    10ul,
    1ul
};
std::string IntToString(uint32_t a1)
{
    int count=0;
    std::string result;
    if (a1==0) return "0";
    for(int i=0;i<10;i++)
    {
        while(a1>=pow10Table32[i])
        {
            a1-=pow10Table32[i];
            count++;
        }
        if (count!=0)
        {
            result+=count+0x30;
            count=0;
        }
    }
    return result;
}
void task1()
{
    uint32_t a1=877567364;
    std::string str=IntToString(a1);
    std::cout<<str;
}

