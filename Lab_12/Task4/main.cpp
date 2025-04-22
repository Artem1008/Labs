#include <getopt.h>
#include "main.h"
#include "threadpool.h"

typedef std::pair<std::string,int> (*EncodingFunction)(unsigned char* bufer,size_t size);
std::pair<std::string,int> EncodingASCII(unsigned char* bufer,size_t size);
std::pair<std::string,int> EncodingCP1251(unsigned char* bufer,size_t size);
std::pair<std::string,int> EncodingCP866(unsigned char* bufer,size_t size);
std::pair<std::string,int> EncodingISO88595(unsigned char* bufer,size_t size);
std::pair<std::string,int> EncodingKOI8R(unsigned char* bufer,size_t size);
std::pair<std::string,int> EncodingUTF8(unsigned char* bufer,size_t size);
std::pair<std::string,int> EncodingUTF16LE(unsigned char* bufer,size_t size);
std::pair<std::string,int> EncodingUTF16BE(unsigned char* bufer,size_t size);
std::pair<std::string,int> EncodingUTF32LE(unsigned char* bufer,size_t size);
std::pair<std::string,int> EncodingUTF32BE(unsigned char* bufer,size_t size);
std::pair<std::string,int> EncodingUCS2(unsigned char* bufer,size_t size);
void PritnfHelp()
{
    std::wcout << L"Использование: ./programm [опции]\n"
               << L"Опции:\n"
               << L"  -p, --path     имя файла\n"
               << L"  -h, --help     показать эту справку\n";
}

int main(int argc, char *argv[] )
{
    setlocale(LC_ALL, "");
    std::string path;
    EncodingFunction encodingfunction[]=
    {
        EncodingASCII,
        EncodingCP1251,
        EncodingCP866,
        EncodingISO88595,
        EncodingKOI8R,
        EncodingUTF8,
        EncodingUTF16LE,
        EncodingUTF16BE,
        EncodingUTF32LE,
        EncodingUTF32BE,
        EncodingUCS2
    };
    //строка для анализа
    unsigned char* buffer;
    static struct option long_options[] = {
    {"path",     required_argument, 0, 'p'},
    {"help",     no_argument,       0, 'h'},
    {0, 0, 0, 0}
};
    int opt;
    while ((opt = getopt_long(argc, argv, "p:h", long_options, NULL)) != -1) {
        switch (opt) {
        case 'p':
            path = optarg;
            break;
        case 'h':
            PritnfHelp();
            return 0;
        default:
            PritnfHelp();
            return 1;
        }
    }
    if (path.empty()) {
        PritnfHelp();
        return 1;
    }
    std::vector<std::future<std::pair<std::string, int>>> futures;
    std::shared_ptr<std::ifstream> file_ptr=std::make_shared<std::ifstream>(path,std::ios::binary);
    if (!file_ptr->is_open())
    {
        std::cerr << "file opening error: " << path << std::endl;
        return 0;
    }
    file_ptr->seekg(0, std::ios::end);
    size_t sizefile=file_ptr->tellg();
    file_ptr->seekg(0,std::ios::beg);
    buffer= new unsigned char[sizefile];
    if (!file_ptr->read((char*)buffer, sizefile))
    {
        std::cerr << "file reading error "<<std::this_thread::get_id()<<"\n";
        return 0;
    }
    //колличество символов в служебном диопозоне
    size_t count32;
    // Проверяем на бинарный файл
    for(size_t i=0;i<sizefile;++i)
    {
        if (buffer[i]< 32 && buffer[i] != '\n' && buffer[i] != '\r' && buffer[i] != '\t')
        {
            ++count32;
        }
        if(count32==sizefile)
        {
            std::wcout << L"Фаил бинарный";
            return -1;
        }
    }
    ThreadPool pool;
    for (size_t i = 0; i <sizeof(encodingfunction)/sizeof(encodingfunction[0]); ++i)
    {
        futures.push_back(pool.enqueue(encodingfunction[i],buffer,sizefile));
    }
    for (const auto& future : futures)
    {
        future.wait();
    }
    for (auto& future : futures)
    {
        auto result = future.get();
        if(result.first=="None")
        {
            std::wcout<<L"Не определено\n";
        }
        else std::cout << result.first <<" : " << result.second<<"%"<<std::endl;
    }
    return 1;
}
#include <function.inl>
