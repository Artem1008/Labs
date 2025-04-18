#include "safemap.h"
typedef std::map<int,int> koordinats;

koordinats SafeMap::getAll()
{
    std::lock_guard<std::mutex> lg(mutex);
    return data;
}
int SafeMap::getNum(int num)
{
    std::lock_guard<std::mutex> lg(mutex);
    auto it = data.find(num);
    if (it != data.end()) {
        return it->second;
    }
    throw std::out_of_range("индекс не найден");
}
void SafeMap::insert(int position)
{
    std::lock_guard<std::mutex> lg(mutex);
    data[++count]=position;
}
void SafeMap::remove(int num)
{
    std::lock_guard<std::mutex> lg1(mutex);
    data.erase(num);
}
size_t SafeMap::size()
{
    std::lock_guard<std::mutex> lg(mutex);
    return data.size();
}
void SafeMap::print()
{
    for(auto& var:data)
    {
        std::wcout<<L"номер совпадения:"<<var.first<<L" позиция:"<<var.second<<'\n';
    }
}
