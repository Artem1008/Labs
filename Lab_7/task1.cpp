#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include  "errors.h"
#define MAXCOUNT 8

std::mutex mmutex;

void thread_func(std::vector<int> &data){
    const std::lock_guard<std::mutex> lock(mmutex);
    int size=data.size();
    data.push_back(data[size-2]+data[size-1]);
}

template<typename T>
void ChekValue(T &Value)
{
    int count=5;
    for(;count>=0;count--)
    {
        std::cin>>Value;
        std::cin.ignore(32767,'\n');
        if (std::cin.fail() )
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout<<"Вы ввели некоректное значение\n";
        }
        if (Value> MAXCOUNT)
        {
            throw  ret::ErrSize;
        }
        return;
    }
    throw  ret::ErrIO;
}

void task1()
{
    unsigned int number;
    std::vector<int> data;
    try
    {
        printf("Введите длину последовательности Фибоначчи:\n");
        ChekValue(number) ;
        //int CoreCount = std::thread::hardware_concurrency();
        data.push_back(0);
        data.push_back(1);
        number=number-2;
        while(number--)
        {
            std::thread(thread_func,std::ref(data)).join();
        }
        for(auto var:data)
        {
           printf("%d ",var);
        }
    }
    catch (ret::erorrs a)
    {
        if (a==ret::ErrIO) printf("Привышено число попыток ввода данных");
        if (a==ret::ErrSize) printf("Привышен размер");
    }
    catch (std::runtime_error &ex)
    {
    std::cerr << ex.what();
     }
}
