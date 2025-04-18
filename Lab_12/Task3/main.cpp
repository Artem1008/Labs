
#include <locale>
#include "main.h"
#include "mytimer.h"
#include "threadpool.h"
#include "safemap.h"

SafeMap safemap;
int SafeMap::count;
void processRead(std::shared_ptr<std::ifstream>& file, size_t start, size_t end, std::string& StrFind)
{
    try {
        size_t findSize = StrFind.size();
        if (start + findSize > end)
        {
            std::cerr << "Ошибка: искомая подстрока выходит за пределы диапазона\n";
            return;
        }
        file->seekg(start);
        std::string buffer;
        buffer.resize(end-start);
        if (!file->read(reinterpret_cast<char*>(buffer.data()), buffer.size()))
        {
            std::cerr << "file reading error\n";
            return;
        }
        size_t pos = 0;
        while((pos = buffer.find(StrFind, pos)) != std::string::npos)
        {
            safemap.insert(start + pos);
             pos += StrFind.length();
        }
    }
    catch (...)
    {
        std::cerr << "error searching for a substring in the number stream"<<std::this_thread::get_id()<<"\n";
    }
}
int main(int argc, char *argv[] )
{
    MyTimer timer;
    //размер блоков для обработки
    int sizeblock=32;
    //количество потоков
    int CountThread=6;
    std::string direct="C:\\test\\";
    std::string path="out.txt";
    std::string  strfild="работ";
    std::vector<std::future<void>> futures;
    std::shared_ptr<std::ifstream> file=std::make_shared<std::ifstream>((path),std::ios::binary);
    if (!file->is_open())
    {
        std::cerr << "file opening error: " << path << std::endl;
        return 0;
    }
    size_t fileSize = file.get()->seekg(0, std::ios::end).tellg();
    ThreadPool pool(CountThread);
    for (int i = 0; i <= (int)fileSize/sizeblock; ++i)
    {
        size_t start = i * sizeblock ;
        size_t end = (start+sizeblock)<fileSize?start+sizeblock:fileSize;
        futures.push_back(pool.enqueue(processRead,file,start,end,strfild));
    }
    for (auto& future : futures)
    {
        future.wait();
    }
    safemap.print();
    return 1;
}
