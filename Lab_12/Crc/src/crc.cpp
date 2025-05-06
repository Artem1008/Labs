
#include  "../include/crc.h"


uint32_t CRC::calculateCRC(const std::string& data)
{
    uint32_t crc;
    switch (type) {
    case CRC4:
        crc = 0xF;
        for (char var:data)
        {
            crc ^= var;
            for (int i = 0; i < 8; ++i)
            {
                if (crc & 1)
                {
                    crc = (crc >> 1) ^ POLINOM_CRC32;
                }
                else
                {
                    crc = crc >> 1;
                }
            }
        }
        return ~crc;
    case CRC8:
        crc = 0xFF;
        for (char var:data)
        {
            crc ^= var;
            for (int i = 0; i < 8; ++i)
            {
                if (crc & 1)
                {
                    crc = (crc >> 1) ^ POLINOM_CRC32;
                }
                else
                {
                    crc = crc >> 1;
                }
            }
        }
        return ~crc;
    case CRC16:
        crc= 0xFFFF;
        for (char var:data)
        {
            crc ^= var;
            for (int i = 0; i < 8; ++i)
            {
                if (crc & 1)
                {
                    crc = (crc >> 1) ^ POLINOM_CRC32;
                }
                else
                {
                    crc = crc >> 1;
                }
            }
        }
        return ~crc;
    case CRC32:
        crc = 0xFFFFFFFF;
        for (char var:data)
        {
            crc ^= var;
            for (int i = 0; i < 8; ++i)
            {
                if (crc & 1)
                {
                    crc = (crc >> 1) ^ POLINOM_CRC32;
                }
                else
                {
                    crc = crc >> 1;
                }
            }
        }
        return ~crc;
    default:
        return 0;

    }
    return 0;
}
uint32_t CRC::getchecksum(const std::string& data)
{
    uint32_t checksum = 0;
    for (char var:data)
    {
        checksum += var;
    }
    return checksum;
}
void CRC::setCRCType(const char * _type)
{
    if (strcmp(_type,"crc4")==0)  type=CRCType::CRC4;
    else if (strcmp(_type,"crc8")==0)  type=CRCType::CRC8;
    else if (strcmp(_type,"crc16")==0)  type=CRCType::CRC16;
    else if (strcmp(_type,"crc32")==0)  type=CRCType::CRC32;
}
