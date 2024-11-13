#include <iostream>
#include "main.h"

template<typename T>
void ((*actions[])(T*,int,int)){PyramidSort, EnumerationSort, BubbleSort, HaorSort};
int main() {
    int type=0;
    int size=0;
    int typeSort=0;

    while(true)
    {
        InputType(type);
        InputSize(size);
        InputSort(typeSort);
        if(size>0)
        {
            if(type==1)
            {
                char* pArr;
                void(*action)(char*,int, int );
                CreateArray(pArr,size);
                for(int i=0;size>i;i++)
                {
                    std::cout<<pArr[i]<<" ";
                }
                std::cout<<"\n";
                action=select(1);
                if(action) action(pArr,0,size-1);
                for(int i=0;size>i;i++)
                {
                    std::cout<<pArr[i]<<" ";
                }
                std::cout<<'\n';
            }
            else if(type==2)
            {
                short* pArr;
                void(*action)(short*,int, int );
                CreateArray(pArr,size);
                for(int i=0;size>i;i++)
                {
                    std::cout<<pArr[i]<<" ";
                }
                std::cout<<"\n";

                for(int i=0;size>i;i++)
                {
                    std::cout<<pArr[i]<<" ";
                }
                std::cout<<'\n';
            }
            else if(type==3)
            {
                int* pArr;
                void(*action)(int*,int, int );
                CreateArray(pArr,size);
                for(int i=0;size>i;i++)
                {
                    std::cout<<pArr[i]<<" ";
                }
                std::cout<<"\n";

                for(int i=0;size>i;i++)
                {
                    std::cout<<pArr[i]<<" ";
                }
                std::cout<<'\n';
            }
            else if(type==4)
            {
                float* pArr;
                void(*action)(float*,int, int );
                CreateArray(pArr,size);
                for(int i=0;size>i;i++)
                {
                    std::cout<<pArr[i]<<" ";
                }
                std::cout<<"\n";

                for(int i=0;size>i;i++)
                {
                    std::cout<<pArr[i]<<" ";
                }
                std::cout<<'\n';
            }
            else if(type==5)
            {
                double* pArr;
                void(*action)(double*,int, int );
                CreateArray(pArr,size);
                for(int i=0;size>i;i++)
                {
                    std::cout<<pArr[i]<<" ";
                }
                std::cout<<"\n";

                for(int i=0;size>i;i++)
                {
                    std::cout<<pArr[i]<<" ";
                }
                std::cout<<'\n';
            }
            else if (type==9)
            {
                printf("До свидания\n");
                return 0;
            }
            else printf("Типа под данным номером не существует\n");
        }
        else
        {
            printf("размер слишком мал\n");
        }
    }

}
template<typename T>
void(*select(int choice))(T* ,int,int)
{
    if (choice >0 && choice<5)
    return actions[choice - 1];
    else
    return nullptr;
}
void InputType(int & type)
{
    printf("Введите тип массива:\n");
    printf("1. char\n");
    printf("2. short\n");
    printf("3. int\n");
    printf("4. float\n");
    printf("5. double\n");
    printf("9. Выход\n");
    ChekValue(type);
}
void InputSort(int & type)
{
    printf("Введите Метод сортировки:\n");
    printf("1. Перебор\n");
    printf("2. Пузырька\n");
    printf("3. Хаора\n");
    printf("4. Пирамидальной\n");
    printf("9. Выход\n");
    ChekValue(type);
}
void InputSize(int & size)
{
    printf("Введите размер массива:\n");
    ChekValue(size);
}
template<typename T>
void CreateArray(T* &pArr,int size)
{
    pArr=new T[size];
    srand(7777);
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX)+1.0);
    for (int i=0; i<size; i++)
    {
        pArr[i]=static_cast<int>(rand() * fraction * (MAXVALUE-MINVALUE+1) +MINVALUE);
    }
}
template<typename T>
void BubbleSort(T* pArr,int begin, int end)
{
std::cout<<"BubbleSort";
}
template<typename T>
void PyramidSort(T* pArr,int begin, int end)
{
    std::cout<<"PyramidSort";
}
template<typename T>
void EnumerationSort(T* pArr,int begin, int end)
{
    std::cout<<"EnumerationSort";
}
template<typename T>
void HaorSort(T* pArr,int begin, int end)
{
    std::cout<<"HaorSort";
}
template<typename T>
void Quicksort(T* pArr,int begin, int end)
{
    if (begin<end)
    {
        int middle=Partition(pArr,begin,end);
        Quicksort(pArr,begin,middle-1);
        Quicksort(pArr,middle+1,end);
    }
}
template<typename T>
int Partition(T* pArr,int begin, int end)
{
    int x=pArr[end];
    int i=begin-1;
    for(int j=begin;j<end;j++)
    {
        if (pArr[j]<=x)
        {
            ++i;
            std::swap(pArr[i],pArr[j]);
        }
    }
    std::swap(pArr[i+1],pArr[end]);
    return ++i;
}
template<typename T>
int ChekValue(T &Value)
{
    int count=5;
    for(;count>=0;count--)
    {
        std::cin>>Value;
        std::cin.ignore(32767,'\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout<<"Вы ввели некоректное значение\n";
        }
        else return 1;
    }
    std::cout<<"Привышено число попыток ввода данных\n";
    return -1;
}
