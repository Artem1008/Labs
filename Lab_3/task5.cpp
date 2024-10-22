#include <iostream>

int SeekMax(int var1,int var2)
{
    return (var1>var2)?var1:var2;
}
unsigned short SeekMax(unsigned short var1,unsigned short var2)
{
    return (var1>var2)?var1:var2;
}
//через массив или вектор конечно было бы проще
int SeekMax(int var1,int var2,int var3)
{
    int temp;
    temp=var1;
    temp=(temp>var2)?temp:var2;
    temp=(temp>var3)?temp:var3;
     return temp;
}
int SeekMin(int var1,int var2)
{
    return (var1>var2)?var2:var1;
}
unsigned short SeekMin(unsigned short var1,unsigned short var2)
{
    return (var1>var2)?var2:var1;
}
//через массив или вектор конечно было бы проще
int SeekMin(int var1,int var2,int var3)
{
    int temp;
    temp=var1;
    temp=(temp>var2)?var2:temp;
    temp=(temp>var3)?var3:temp;
    return temp;
}
template<typename T>
int ChekValue(T &Value,int L)
{
    for(int i=0;i<L;i++)
    {
        std::cin>>Value[i];
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout<<" Некорректное значение\n";
            i=-1;
        }
    }
    return 1;
}
