/* ������ୠ� ࠡ�� �12
 * �� ⥬�:��᫥������� ��ࠬ��஢ �㭪樨 main, ���᮫쭮� ᡮઠ �஥��, ����� �ਫ������, ࠧࠡ�⪠ ����᪨� � �������᪨� ������⥪ �++ � IDE Qt Creator
 * ���� ࠡ���:
 * 1. ���९��� �� �ࠪ⨪� ࠡ��� � ��ࠬ��ࠬ� �㭪樨 main, ���᮫쭮� ᡮમ� � ����᪮�.
 * 2. �������� ᮧ������ ����᪨� � �������᪨� ������⥪� �� �++.
 * 3. �⢥��� �� ��⮢� ������.
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
        std::cerr << "�訡�� ������ 䠩��: " << path << std::endl;
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


