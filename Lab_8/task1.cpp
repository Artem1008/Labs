#include <vector>
#include <map>
#include <myfuct.h>

template<typename T>
int ChekVector(const std::vector<T>&);
int task1()
{
    int N;
    printf("Введите количество элементов N:");
    if(!ChekValue(N))
    {
       return -1;
    }
    std::vector<int> arr;
    printf("Содержимое контейнера:\n");
    CreateCont(arr,N);
    std::cout<<arr;
    printf("Уникальных чисел:");
    std::cout<<ChekVector(arr);
      return 1;
}
template<typename T>
int ChekVector(const std::vector<T>& vec)
{
    int Count=0;
    std::map<T,int> temp;
    for(auto &var:vec)
    {
        temp[var]=++temp[var];
    }
    for(auto &var : temp)
    {
       if(var.second==1)
        Count++;
    }
    return Count;
}


