#include "main.h"

int main(int argc, char *argv[] )
{
    std::string bufer;
    const char* path;
    size_t size;
    CRC crc32;
    uint32_t crc;
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
    crc32.setCRCType("crc16");
    crc=crc32.calculateCRC(bufer);
    file.close();
    std::cout<<"crc="<< std::hex<<crc;
    return 0;
}

