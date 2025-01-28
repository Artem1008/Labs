#include <iostream>
#include <vector>
#include <ctime>
#include <map>

unsigned long rand32(void)
{
    static unsigned long long rand = time(NULL);
    rand *= 134775813;
    rand += 1;
    return (unsigned long) (rand >> 32);
}
template<typename T>
int ChekVector(const std::vector<T>&);
template<typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T>&);
template<typename T>
int ChekValue(T &);
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
    for(int i=0;i<N;i++)
    {
        arr.push_back(rand32());
        //Используйте перегрузку ввода и вывода (cout, cin).
        std::cout<<arr;
        /*
        printf("%d ",arr[i]);
        if (((i+1)%10==0)) printf("\n");
        */
    }
    printf("Уникальных чисел:");
    std::cout<<ChekVector(arr);
      return 1;
}
template<typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& vec)
{
   os.width(12);
   os<<vec.back();
   if (vec.size()%10==0) os<<'\n';
   return os;
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
