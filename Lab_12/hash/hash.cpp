/* Лабораторная работа №12
 * на тему:Исследование параметров функции main, консольной сборка проекта, запуск приложения, разработка статических и динамических библиотек С++ в IDE Qt Creator
 * Цели работы:
 * 1. Закрепить на практике работу с параметрами функции main, консольной сборкой и запуском.
 * 2. Научиться создавать статические и динамические библиотеки на С++.
 * 3. Ответить на тестовые вопросы.
 * Developer Zvorygin Artem
*/
#include  "../include/hash.h"

uint32_t leftRotate(uint32_t value, int shift) {
    return (value << shift) | (value >> (32 - shift));
}
std::function<uint32_t(uint32_t, uint32_t, uint32_t)> lambdas[] = {
    [](uint32_t x, uint32_t y, uint32_t z) { return (x & y)|((~x) & z); },
    [](uint32_t x, uint32_t y, uint32_t z) { return (x & z)|((~z)&y); },
    [](uint32_t x, uint32_t y, uint32_t z) { return x^y^z; },
    [](uint32_t x, uint32_t y, uint32_t z) { return y^((~z)|x); }
};
std::string convert(uint32_t x)
{
    std::stringstream ss;
    ss<<std::hex<<std::setfill('0');
    ss<<std::setw(2)<<static_cast<int>((x) & 0xFF);
    ss<<std::setw(2)<<static_cast<int>((x >> 8) & 0xFF);
    ss<<std::setw(2)<< static_cast<int>((x >> 16) & 0xFF);
    ss<<std::setw(2)<<static_cast<int>((x >> 24) & 0xFF);
    return ss.str();
};
std::string Hash::calculatemd5(const std::string & data)
{
    InitMD5();
    std::string str=data;
    size_t size=str.size();
    std::string bits;

    for(int i = 0; i < 8; i++)
    {
        bits.push_back( (unsigned char)((size*8 >> (8 * i)) & 0xFF));
    }
    str.push_back(0x80);
    if((size%64)>=56)
    {
        str.append(63-size%64,0);
        str.append(56,0);
    }
    else
    {
        str.append(63-size%64-8,0);
    }
    str.append(bits);
    // Раунды обновления хеш-значения
    size_t indexM{0};
    size_t sizeBlocks = str.size() / 64;
    const uint32_t* Firstblock = reinterpret_cast<const uint32_t*>(str.data());
    for (size_t i = 0; i < sizeBlocks; ++i) {
        uint32_t a = A;
        uint32_t b = B;
        uint32_t c = C;
        uint32_t d =D;
        M = Firstblock + i * 16;
        for (size_t i = 0; i < 64; ++i)
        {

            if (i < 16)indexM = i;
            else if (i < 32) indexM = (5 * i + 1) % 16;
            else if (i < 48) indexM = (3 * i + 5) % 16;
            else indexM = (7 * i) % 16;
            a = leftRotate(a+lambdas[i/16](b, c, d) + M[indexM] +k[i],s[i])+b;
            uint32_t temp = a;
            a=d;
            d=c;
            c=b;
            b=temp;
        }
        A += a;
        B += b;
        C += c;
        D += d;
    }
    // Формирование хеш-значения
    std::string hash;
    hash.append(convert(A));
    hash.append(convert(B));
    hash.append(convert(C));
    hash.append(convert(D));
    return hash;
}/*
std::string Hash::calculatesha256(const std::string & data)
{
}
std::string Hash::calculatesha512(const std::string & data)
{
}*/
void Hash::setHashType(const char * _type)
{
    if (strcmp(_type,"md5")==0)  type=HashType::MD5;
    else if (strcmp(_type,"sha256")==0)  type=HashType::SHA256;
    else if (strcmp(_type,"sha512")==0)  type=HashType::SHA512;
}
void Hash::InitMD5()
{
    uint8_t _a[4] = { 0x01, 0x23, 0x45, 0x67 };
    uint8_t _b[4] = { 0x89, 0xab, 0xcd, 0xef };
    uint8_t _c[4] = { 0xfe, 0xdc, 0xba, 0x98 };
    uint8_t _d[4] = { 0x76, 0x54, 0x32, 0x10 };
    A = *reinterpret_cast<uint32_t*>(&_a);
    B = *reinterpret_cast<uint32_t*>(&_b);
    C = *reinterpret_cast<uint32_t*>(&_c);
    D = *reinterpret_cast<uint32_t*>(&_d);
}
