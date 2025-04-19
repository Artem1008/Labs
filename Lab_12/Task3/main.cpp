#include <locale>
#include "main.h"
#include "mytimer.h"
#include "threadpool.h"
#include "safemap.h"
#include <mutex>
#include <chrono>

std::mutex readMutex;
SafeMap safemap;
int SafeMap::count;

void processRead(std::shared_ptr<std::ifstream> file_ptr, size_t start, size_t end,const std::string& StrFind)
{
    auto timestart=std::chrono::high_resolution_clock::now();
    size_t findSize = StrFind.size();
    if (start + findSize > end)
    {
        std::cerr << "Ошибка: искомая подстрока выходит за пределы диапазона\n";
        return;
    }
    std::string buffer;
    buffer.resize(end-start);
    readMutex.lock();
    file_ptr->seekg(start);
    if (!file_ptr->read(&buffer[0], buffer.size()))
    {
        std::cerr << "file reading error "<<std::this_thread::get_id()<<"\n";
        return;
    }
    readMutex.unlock();
    size_t pos = 0;
    while((pos = buffer.find(StrFind, pos)) != std::string::npos)
    {
        safemap.insert(start + pos);
        pos += StrFind.length();
    }
    readMutex.lock();
    auto timeend=std::chrono::high_resolution_clock::now();
    std::cout <<"potok nomer "<<std::this_thread::get_id()<<"srabotal za "<<std::chrono::duration_cast<std::chrono::milliseconds>(timeend - timestart).count()<<" millisec \n";
    readMutex.unlock();
}
int main()
{

    //размер блоков для обработки
    int sizeblock=32;
    //количество потоков
    int CountThread=6;
    std::string direct="C:\\test\\";
    std::string path="out.txt";
    //строка для поиска
    std::string  strfild="работ";
    std::vector<std::future<void>> futures;
    std::shared_ptr<std::ifstream> file_ptr=std::make_shared<std::ifstream>(path,std::ios::binary);
    if (!file_ptr->is_open())
    {
        std::cerr << "file opening error: " << path << std::endl;
        return 0;
    }
    size_t fileSize = file_ptr.get()->seekg(0, std::ios::end).tellg();
    ThreadPool pool(CountThread);
    for (int i = 0; i <= (int)fileSize/sizeblock; ++i)
    {
        size_t start = i * sizeblock ;
        size_t end = (start+sizeblock)<fileSize?start+sizeblock:fileSize;
        futures.push_back(pool.enqueue(processRead,file_ptr,start,end,strfild));
    }
    for (auto& future : futures)
    {
        future.wait();
    }
    safemap.print();
    return 1;
}
