#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <cstring>

#define POLINOM_CRC4 0x3
#define POLINOM_CRC8 0x31
#define POLINOM_CRC16 0x1021
#define POLINOM_CRC32 0xEDB88320

class CRC
{
public:
    enum CRCType {
        CRC4,
        CRC8,
        CRC16,
        CRC32
    };
    CRC():type(CRC32){};
    uint32_t calculateCRC(const std::string&);
    uint32_t getchecksum(const std::string&);
    void setCRCType(const char*);
private:

    CRCType type;



};
#endif // MAIN_H
