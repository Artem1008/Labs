/* Лабораторная работа №12
 * на тему:Исследование параметров функции main, консольной сборка проекта, запуск приложения, разработка статических и динамических библиотек С++ в IDE Qt Creator
 * Цели работы:
 * 1. Закрепить на практике работу с параметрами функции main, консольной сборкой и запуском.
 * 2. Научиться создавать статические и динамические библиотеки на С++.
 * 3. Ответить на тестовые вопросы.
 * Developer Zvorygin Artem
*/

#include "crc.h"
#include "hash.h"
#include <fstream>
#include <string>

int main(int argc, char *argv[] )
{
    std::string bufer;
    const char* path;
    Hash _hash;
    CRC crc;
    if (argc>1)
    {
        path=argv[1];
    }
  std::ifstream file(path,std::ios::binary);
 if (!file.is_open())
    {
        std::cerr << "Ошибка открытия файла: " << path << std::endl;
        return 0;
    }
    file.seekg(0,std::ios_base::end);
    bufer.resize(file.tellg());
    file.seekg(0, std::ios::beg);
    file.read(&bufer[0], bufer.size());
    std::cout<<"crc="<< std::hex<<crc.calculateCRC(bufer)<<"\n";
    std::cout<<"md5="<< std::hex<<hash.calculatemd5(bufer)<<"\n";
     //file.close();
    return 0;
}


