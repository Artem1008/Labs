#include <thread>
#include <vector>
#include <map>
#include <mutex>
#include <algorithm>
#include <utility>
#include <iostream>
#include <condition_variable>
#include "CLog.h"
#define MaxElement 10

std::map<const char *,int> logarr;
std::condition_variable data_cond;
std::mutex mutex3;
bool gexit;
void RandomArr(std::vector<int>& arr)
{
    arr.clear();
    while(!gexit)
    {
        std::lock_guard<std::mutex> lock(mutex3);
        arr.push_back(rand()%100);
        if (arr.back()<10) logarr.insert(std::make_pair("AlarmMessage",CLog::Priority::Alarm));
        else if (arr.back()>10&&arr.back()<20) logarr.insert(std::make_pair("ErrorMessage",CLog::Priority::Error));
        else if (arr.back()>20&&arr.back()<30) logarr.insert(std::make_pair("WarningMessage",CLog::Priority::Warning));
        else if (arr.back()>30&&arr.back()<40) logarr.insert(std::make_pair("SystemInformation",CLog::Priority::System));
        else if (arr.back()>40&&arr.back()<50) logarr.insert(std::make_pair("ServiceInformation",CLog::Priority::Service));
        else if (arr.back()>50&&arr.back()<60) logarr.insert(std::make_pair("DebuggingInformation",CLog::Priority::Debugging));
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
void SortArr(std::vector<int>& arr)
{
    while(!gexit)
    {

        if (!arr.empty())
        {
            std::lock_guard<std::mutex> lock(mutex3);
            std::sort(arr.begin(), arr.end());
        }
    }
}
void PrintArr(std::vector<int>& arr)
{
    while(!gexit)
    {

        if (!arr.empty())
        {
            const std::lock_guard<std::mutex> lock(mutex3);
            for(auto var:arr)
            {
                std::cout<<var<<" ";
            }
            std::cout<<'\n';
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}
void PrintLog(std::map<const char *,int>& logarr)
{

    while(!gexit)
    {
        if (!logarr.empty())
        {
            for(auto &var : logarr)
            {
                CLog::PrintMessage(var.second,var.first);
            }
            logarr.clear();
        }
    }
}
void task5()
{
    std::vector<int> arr;
    gexit=false;
    srand((int)time(0));
    CLog::SetLevel(CLog::Priority::Alarm|CLog::Priority::Error);
    std::thread t1(RandomArr,std::ref(arr));
    std::thread t2(SortArr,std::ref(arr));
    std::thread t3(PrintArr,std::ref(arr));
    std::thread log(PrintLog,std::ref(logarr));
    t1.join();
    t2.join();
    t3.join();
    log.join();
}
