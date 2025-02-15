#ifndef MYFUCT_H
#define MYFUCT_H
#include <ctime>
#include <iostream>
#include <vector>
#include <list>

/**
* @brief Функция рандома
*/
int rand32(void);
/**
* @brief проверки данных
*/

template<typename T>
int ChekValue(T &Value)
{
    int temp;
    int count=5;
    for(;count>=0;count--)
    {
        scanf("%d", &temp);
        if ((temp>1000)||(temp<0))
        {
            printf("%s","Вы ввели некоректное значение\n");
        }
        else
        {
            Value=temp;
            return 1;
        }
    }
    std::cout<<"Привышено число попыток ввода данных\n";
    return 0;
}

template<typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& vec)
{

    for (size_t index = 0; index < vec.size(); ++index)
    {
        os.width(12);
        os<<vec[index];
        if (((index+1)!=vec.size())&&(index+1)%10==0) os<<'\n';
    }
    os<<'\n';
    return os;
}
template<typename T>

std::ostream& operator << (std::ostream& os, const std::list<T>& list)
{
    int index=0;
    for (auto var:list)
    {
        ++index;
        os.width(12);
        os<<var;
        if (((index+1)!=list.size())&&(index+1)%10==0)
        {
            index=0;
            os<<'\n';
        }
    }
    os<<'\n';
    return os;
}
template<typename T>
T Average (const std::vector<T>& vec)
{
    T sum;
    for(const auto& var:vec)
    {
        sum+=var;
    }
    return sum/vec.size();
}
template<typename T>
int CreateCont(T &Value,int size)
{
    for(int i=0;i<size;i++)
    {
        Value.push_back(rand32());
    }
}
#endif // MYFUCT_H
