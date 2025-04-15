#include "crc.h"
#include <fstream>
#include <string>

int main(int argc, char *argv[] )
{
    std::string bufer;
    const char* path;
    Hash hash;
    std::string rezult;
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
    rezult=hash.calculateCRC32(bufer);
    std::cout<<"crc="<< std::hex<<rezult<<"\n";
    rezult=hash.calculatemd5(bufer);
    std::cout<<"md5="<< std::hex<<rezult<<"\n";
     //file.close();
    return 0;
}


