#include <locale>
#include <mutex>
#include <vector>
#include <chrono>
#include <getopt.h>
#include "main.h"
#include "threadpool.h"

std::mutex readMutex;

// Определяем диапазоны символов для каждой кодировки
struct CharRange {
    std::string name;
    std::pair<int, int> range1;  // для русских букв
    std::pair<int, int> range2;  // для английских букв
};

// Массив с диапазонами символов для разных кодировок
const std::vector<CharRange> ranges = {
    {"ASCII", {0, 0}, {32, 126}},
    {"CP1251", {192, 255}, {32, 126}},
    {"CP866", {128, 159}, {32, 126}},
    {"ISO8859-5", {128, 191}, {32, 126}},
    {"KOI8-R", {128, 159}, {32, 126}},
    {"KOI8-R", {128, 159}, {32, 126}},
    {"CP866", {128, 159}, {32, 126}},
    {"CP866", {128, 159}, {32, 126}}
};
void processRead(const std::string& StrFind)
{
    readMutex.lock();
    auto timestart=std::chrono::high_resolution_clock::now();
    readMutex.unlock();

    readMutex.lock();
    auto timeend=std::chrono::high_resolution_clock::now();
    std::cout <<"potok nomer "<<std::this_thread::get_id()<<" srabotal za "<<std::chrono::duration_cast<std::chrono::nanoseconds>(timeend - timestart).count()<<" nanosec \n";
    readMutex.unlock();
}
void PritnfHelp()
{
    std::wcout << L"Использование: ./programm [опции]\n"
               << L"Опции:\n"
               << L"  -p, --path     имя файла\n";
}

int main(int argc, char *argv[] )
{
    setlocale(LC_ALL, "");
    std::string path;
    //строка для анализа
    std::string  buffer;
    static struct option long_options[] = {
    {"path",     required_argument, 0, 'p'},
    {0, 0, 0, 0}
};
    int opt;
    while ((opt = getopt_long(argc, argv, "p:t:f:c:h", long_options, NULL)) != -1) {
        switch (opt) {
        case 'p':
            path = optarg;
            break;
        default:
            PritnfHelp();
            return 1;
        }
    }
    if (path.empty()) {
        PritnfHelp();
        return 1;
    }
    std::vector<std::future<void>> futures;
    std::shared_ptr<std::ifstream> file_ptr=std::make_shared<std::ifstream>(path,std::ios::binary);
    if (!file_ptr->is_open())
    {
        std::cerr << "file opening error: " << path << std::endl;
        return 0;
    }
    file_ptr->seekg(0, std::ios::end);
    size_t sizefile=file_ptr->tellg();
    file_ptr->seekg(0,std::ios::beg);
    buffer.resize(sizefile);
    if (!file_ptr->read(&buffer[0], buffer.size()))
    {
        std::cerr << "file reading error "<<std::this_thread::get_id()<<"\n";
        return 0;
    }
    ThreadPool pool;
    for (int i = 0; i <= 5; ++i)
    {
        futures.push_back(pool.enqueue(processRead,buffer));
    }
    for (auto& future : futures)
    {
        future.wait();
    }
    return 1;
}
