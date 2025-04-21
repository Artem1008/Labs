#include <locale>
#include "main.h"
#include "mytimer.h"
#include "threadpool.h"
#include "safemap.h"
#include <mutex>
#include <chrono>
#include <getopt.h>
//#define MULIREAD

std::mutex readMutex;
SafeMap safemap;
int SafeMap::count;

//2 варианта чтения последовательное каждым потоком или многопоточное
void processRead(const std::shared_ptr<std::ifstream>& file_ptr,const std::string& path, size_t start, size_t end,const std::string& StrFind)
{
    readMutex.lock();
    auto timestart=std::chrono::high_resolution_clock::now();
    readMutex.unlock();
    size_t findSize = StrFind.size();
    if (start + findSize > end)
    {
        std::cerr << "Ошибка: искомая подстрока выходит за пределы диапазона\n";
        return;
    }
    std::string buffer;
    buffer.resize(end-start);
#ifdef MULIREAD
    std::shared_ptr<std::ifstream> fileptr=std::make_shared<std::ifstream>(path,std::ios::binary);
    if (!fileptr->is_open())
    {
        std::cerr << "file opening error: " << path << std::endl;
        return;
    }
    fileptr->seekg(start);
    if (!fileptr->read(&buffer[0], buffer.size()))
    {
        std::cerr << "file reading error "<<std::this_thread::get_id()<<"\n";
        return;
    }
#endif
#ifndef MULIREAD
    readMutex.lock();
    file_ptr->seekg(start);
    if (!file_ptr->read(&buffer[0], buffer.size()))
    {
        std::cerr << "file reading error "<<std::this_thread::get_id()<<"\n";
        return;
    }
    readMutex.unlock();
#endif
    size_t pos = 0;

    while((pos = buffer.find(StrFind, pos)) != std::string::npos)
    {
        safemap.insert(start + pos);
        pos += StrFind.length();
    }
    readMutex.lock();
    auto timeend=std::chrono::high_resolution_clock::now();
    std::wcout <<L"Поток номер "<<std::this_thread::get_id()<<L" сработал за "<<std::chrono::duration_cast<std::chrono::nanoseconds>(timeend - timestart).count()<<L" наносек \n";
    readMutex.unlock();
}
void PritnfHelp()
{
    std::wcout << L"Использование: ./programm [опции]\n"
               << L"Опции:\n"
               << L"  -p, --path     имя файла\n"
               << L"  -t, --threads  количество потоков (кратное 2)\n"
               << L"  -f, --fild     строка для поиска\n"
               << L"  -c, --chunk    размер порции чтения\n"
               << L"  -h, --help     показать эту справку\n";
}
//-p "D:\Lads\Task3\out.txt" -t 8 -f "работа" -c 32
int main(int argc, char *argv[] )
{
    setlocale(LC_ALL, "");
    //размер блоков для обработки
    int sizeblock=32;
    //количество потоков
    int CountThread=8;
    std::string path;
    //строка для поиска
    std::string  strfild="работ";

    static struct option long_options[] = {
    {"path",     required_argument, 0, 'p'},
    {"threads",  required_argument, 0, 't'},
    {"fild",     required_argument, 0, 'f'},
    {"chunk",    required_argument, 0, 'c'},
    {"help",     no_argument,       0, 'h'},
    {0, 0, 0, 0}
    };
    int opt;
    while ((opt = getopt_long(argc, argv, "p:t:f:c:h", long_options, NULL)) != -1) {
        switch (opt) {
        case 'p':
            path = optarg;
            break;
        case 't':
            CountThread = atoi(optarg);
            break;
        case 'f':
            strfild = optarg;
            break;
        case 'c':
            sizeblock = atoi(optarg);
            break;
        case 'h':
            PritnfHelp();
            return 0;
        default:
            PritnfHelp();
            return 1;
        }
    }
    if (path.empty() || CountThread <= 0 || strfild.empty() || sizeblock <= 0) {
        PritnfHelp();
        return 1;
    }
    if (CountThread % 2 != 0) {
        std::wcout << L"Количество потоков должно быть кратным 2\n";
        return 1;
    }
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
        futures.push_back(pool.enqueue(processRead,file_ptr,path,start,end,strfild));
    }
    for (auto& future : futures)
    {
        future.wait();
    }
    safemap.print();
    return 1;
}
