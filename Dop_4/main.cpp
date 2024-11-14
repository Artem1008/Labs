#include <iostream>
#include <ctime>
#include <cmath>
#include "main.h"

template<typename T>
void(*select(int))(T*,int);
template<typename T>
void ((*actions[])(T*,int)){EnumerationSort,BubbleSort,FirsStart,PyramidSort};
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
                void(*action)(char*,int) {select<char>(typeSort)};
                AccumMem(pArr,size);
                if(action) action(pArr,size);
                PrintArray(pArr,size);
                FreeMem(pArr);
            }
            else if(type==2)
            {
                short* pArr;
                void(*action)(short*,int) {select<short>(typeSort)};
                AccumMem(pArr,size);
                if(action) action(pArr,size);
                PrintArray(pArr,size);
                FreeMem(pArr);
            }
            else if(type==3)
            {
                int* pArr;
                void(*action)(int*,int) {select<int>(typeSort)};
                AccumMem(pArr,size);
                if(action) action(pArr,size);
                PrintArray(pArr,size);
                FreeMem(pArr);
            }
            else if(type==4)
            {
                float* pArr;
                void(*action)(float*,int) {select<float>(typeSort)};
                AccumMem(pArr,size);
                if(action) action(pArr,size);
                PrintArray(pArr,size);
                FreeMem(pArr);
            }
            else if(type==5)
            {
                double* pArr;
                void(*action)(double*,int) {select<double>(typeSort)};
                AccumMem(pArr,size);
                if(action) action(pArr,size);
                PrintArray(pArr,size);
                FreeMem(pArr);
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
void(*select(int choice))(T*,int)
{
    if (choice >0 && choice<5) return actions<T>[choice - 1];
    else return nullptr;
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
    if (type==9) exit(0);
}
void InputSort(int & typeSort)
{
    printf("Введите Метод сортировки:\n");
    printf("1. Перебор\n");
    printf("2. Пузырька\n");
    printf("3. Хаора\n");
    printf("4. Пирамидальной\n");
    printf("9. Выход\n");
    ChekValue(typeSort);
    if (typeSort==9) exit(0);
}
void InputSize(int & size)
{
    printf("Введите размер массива:\n");
    ChekValue(size);
}
template<typename T>
void AccumMem(T* &pArr,int size)
{
    pArr=new (std::nothrow)T[size];
    GeneralValue(pArr,size);
}
template<typename T>
void FreeMem(T* &pArr)
{
    if (pArr) delete[] pArr;
    pArr = nullptr;
}
template<typename T>
void GeneralValue(T* &pArr,int size)
{
   double maxValue{std::pow(255, sizeof(*pArr))};
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        *(pArr + i) = static_cast<T>(1 + rand() % (int)maxValue);
        std::cout<<*(pArr + i)<<" ";
    }
    std::cout<<'\n';
}
template<typename T>
void PrintArray(T* pArr,int size)
{
    for(int i=0;size>i;i++)
    {
        std::cout<<pArr[i]<<" ";
    }
    std::cout<<'\n';
}
template<typename T>
void BubbleSort(T* pArr,int size)
{
    printf("Сортировка методом пузырька\n");
    while(size--) {
        bool swapped = false;
        for(int i = 0; i < size; i++)
        {
            if(pArr[i] > pArr[i + 1])
            {
                std::swap(pArr[i], pArr[i + 1]);
                swapped = true;
            }
        }
        if(swapped == false)
            break;
    }
}
template<typename T>
void heapify(T* pArr, int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && pArr[l] > pArr[largest])
        largest = l;

    if (r < n && pArr[r] > pArr[largest])
        largest = r;

    if (largest != i)
    {
        std::swap(pArr[i], pArr[largest]);
        heapify(pArr, n, largest);
    }
}

template<typename T>
void PyramidSort(T* pArr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(pArr, n, i);
    for (int i=n-1; i>=0; i--)
    {
        std::swap(pArr[0], pArr[i]);
        heapify(pArr, i, 0);
    }
}
template<typename T>
void EnumerationSort(T* pArr,int size)
{
    for(int i = 0; i < size; i++)
    {
        int LittlePosition = LookLittle(pArr, i, size);
        std::swap(pArr[i], pArr[LittlePosition]);
    }
}
template<typename T>
int LookLittle(T* pArr,int start, int size)
{
    int LittlePosition=size-1;
    for(int i=size-1;i<start;i--)
    {
        if(pArr[LittlePosition]>pArr[i]) LittlePosition=i;
    }
    return LittlePosition;
}
template<typename T>
void FirsStart(T* pArr,int size)
{
    Quicksort(pArr,0,size-1);
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
