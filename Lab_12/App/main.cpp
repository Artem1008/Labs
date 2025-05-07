/* ‹ ¡®à â®à­ ï à ¡®â  ü12
 * ­  â¥¬ã:ˆáá«¥¤®¢ ­¨¥ ¯ à ¬¥âà®¢ äã­ªæ¨¨ main, ª®­á®«ì­®© á¡®àª  ¯à®¥ªâ , § ¯ãáª ¯à¨«®¦¥­¨ï, à §à ¡®âª  áâ â¨ç¥áª¨å ¨ ¤¨­ ¬¨ç¥áª¨å ¡¨¡«¨®â¥ª ‘++ ¢ IDE Qt Creator
 * –¥«¨ à ¡®âë:
 * 1. ‡ ªà¥¯¨âì ­  ¯à ªâ¨ª¥ à ¡®âã á ¯ à ¬¥âà ¬¨ äã­ªæ¨¨ main, ª®­á®«ì­®© á¡®àª®© ¨ § ¯ãáª®¬.
 * 2.  ãç¨âìáï á®§¤ ¢ âì áâ â¨ç¥áª¨¥ ¨ ¤¨­ ¬¨ç¥áª¨¥ ¡¨¡«¨®â¥ª¨ ­  ‘++.
 * 3. Žâ¢¥â¨âì ­  â¥áâ®¢ë¥ ¢®¯à®áë.
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
        std::cerr << "Žè¨¡ª  ®âªàëâ¨ï ä ©« : " << path << std::endl;
        return 0;
    }
    file.seekg(0,std::ios_base::end);
    bufer.resize(file.tellg());
    file.seekg(0, std::ios::beg);
    file.read(&bufer[0], bufer.size());
    std::cout<<"crc="<< std::hex<<crc.calculateCRC(bufer)<<"\n";
    std::cout<<"md5="<< std::hex<<hash.calculatemd5(bufer)<<"\n";
    std::cout<<"sha256="<< std::hex<<hash.calculatesha256(bufer)<<"\n";
    std::cout<<"sha512="<< std::hex<<hash.calculatesha512(bufer)<<"\n";
    file.close();
    return 0;
}


