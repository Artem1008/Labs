/* Лабораторная работа №12
 * на тему:Исследование параметров функции main, консольной сборка проекта, запуск приложения, разработка статических и динамических библиотек С++ в IDE Qt Creator
 * Цели работы:
 * 1. Закрепить на практике работу с параметрами функции main, консольной сборкой и запуском.
 * 2. Научиться создавать статические и динамические библиотеки на С++.
 * 3. Ответить на тестовые вопросы.
 * Developer Zvorygin Artem
*/
#include  "../include/hash.h"

enum Liters
{
    a,
    b,
    c,
    d,
    e,
    f,
    g,
    h
};
std::function<uint32_t(uint32_t, uint32_t, uint32_t)> lambdas[] = {
    [](uint32_t x, uint32_t y, uint32_t z) { return (x & y)|((~x) & z); },
    [](uint32_t x, uint32_t y, uint32_t z) { return (x & z)|((~z)&y); },
    [](uint32_t x, uint32_t y, uint32_t z) { return x^y^z; },
    [](uint32_t x, uint32_t y, uint32_t z) { return y^((~z)|x); }
};
std::string compress(uint64_t* arr,int size)
{
    std::stringstream ss;
    uint64_t i;
    for (i = 0; i < size; i++) {
        ss<<std::hex<<std::setfill('0');
        ss<<std::setw(2)<<std::hex<<((arr[i] >> 56) & 0xFF);
        ss<<std::setw(2)<< std::hex<<((arr[i] >> 48) & 0xFF);
        ss<<std::setw(2)<<std::hex<<((arr[i] >> 40) & 0xFF);
        ss<<std::setw(2)<<std::hex<<((arr[i]  >> 32)& 0xFF);
        ss<<std::setw(2)<<std::hex<<((arr[i] >> 24) & 0xFF);
        ss<<std::setw(2)<< std::hex<<((arr[i] >> 16) & 0xFF);
        ss<<std::setw(2)<<std::hex<<((arr[i] >> 8) & 0xFF);
        ss<<std::setw(2)<<std::hex<<(arr[i] & 0xFF);
    }
    return ss.str();
};
std::string compress(uint32_t* arr,int size)
{
    std::stringstream ss;
    uint32_t i;
    for (i = 0; i < size; i++) {
         ss<<std::hex<<std::setfill('0');
        ss<<std::setw(2)<<std::hex<<((arr[i] >> 24) & 0xFF);
        ss<<std::setw(2)<< std::hex<<((arr[i] >> 16) & 0xFF);
        ss<<std::setw(2)<<std::hex<<((arr[i] >> 8) & 0xFF);
        ss<<std::setw(2)<<std::hex<<(arr[i] & 0xFF);
    }
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
            a = ROTLEFT(a+lambdas[i/16](b, c, d) + M[indexM] +kmd5[i],s[i])+b;
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
    hash.append(compress(&A,1));
    hash.append(compress(&B,1));
    hash.append(compress(&C,1));
    hash.append(compress(&D,1));
    return hash;
}
std::string Hash::calculatesha256(const std::string & data)
{
    std::string str=data;
    unsigned char bits[8];
    size_t size=data.size();
    for(int i = 0; i < 8; i++)
    {
        bits[7-i]=((unsigned char)((size*8 >> (8 * i)) & 0xFF));
    }
    str.push_back(0x80);
    while((str.size()%64)!=56)
    {
        str.push_back(0);
    }
    for(int i = 0; i < 8; i++)
    {
        str.push_back(bits[i]);
    }
    size_t sizeBlocks = str.size() / 64;
    uint32_t W[64];
    uint32_t tv[8];
    const unsigned char* Firstblock= reinterpret_cast<const unsigned char*>(str.data());
    for (size_t j = 0; j < sizeBlocks; ++j,Firstblock+=64)
    {
        for (int i = 0; i < 8; ++i)
            tv[i] = h256[i];
        for(int i=0;i<16;++i)
        {
            SHA2_PACK32(&Firstblock[i << 2], &W[i]);
        }
        for (size_t i = 16; i < 64; ++i)
        {
            W[i] = W[i-16] + C0(W[i-15]) + W[i-7] + C1(W[i-2]);
        }
        for (int i=0; i<64; ++i){
            uint32_t temp1 = tv[h] + SUM1(tv[e]) + CH(tv[e],tv[f],tv[g]) + k256[i] + W[i];
            uint32_t temp2 = SUM0(tv[a]) + MAJ(tv[a], tv[b], tv[c]);
            tv[h] = tv[g];
            tv[g] = tv[f];
            tv[f] = tv[e];
            tv[e] = tv[d] + temp1;
            tv[d] = tv[c];
            tv[c] = tv[b];
            tv[b] = tv[a];
            tv[a] = temp1 + temp2;
        }
        for (int i = 0; i < 8; ++i)
            h256[i]+=tv[i];
    }
    // Формирование хеш-значения
    std::string hash;
    hash=compress(h256,8);
    return hash;
}

std::string Hash::calculatesha512(const std::string & data)
{
    std::string str=data;
    unsigned char bits[8];
    size_t size=data.size();   
    for(int i = 0; i < 8; i++)
    {
        bits[7-i]=((unsigned char)((size*8 >> (8 * i)) & 0xFF));
    }
    str.push_back(0x80);
    while((str.size()%128)!=120)
    {
        str.push_back(0);
    }
    for(int i = 0; i < 8; i++)
    {
        str.push_back(bits[i]);
    }
    size_t sizeBlocks = str.size() / 128;
    uint64_t W[80];
    uint64_t tv[8];
    const unsigned char* Firstblock= reinterpret_cast<const unsigned char*>(str.data());
    for (size_t j = 0; j < sizeBlocks; ++j,Firstblock+=128)
    {
        for (int i = 0; i < 8; ++i)
            tv[i] = h512[i];
        for(int i=0;i<16;++i)
        {
            SHA2_PACK64(&Firstblock[i << 3], &W[i]);
        }
        for (size_t i = 16; i < 80; ++i)
        {
            W[i] = W[i-16] + C0512(W[i-15]) + W[i-7] + C1512(W[i-2]);
        }
        for (int i=0; i<80; ++i){
            uint64_t temp1 = tv[h] + SUM1512(tv[e]) + CH(tv[e],tv[f],tv[g]) + k512[i] + W[i];
            uint64_t temp2 = SUM0512(tv[a]) + MAJ(tv[a], tv[b], tv[c]);
            tv[h] = tv[g];
            tv[g] = tv[f];
            tv[f] = tv[e];
            tv[e] = tv[d] + temp1;
            tv[d] = tv[c];
            tv[c] = tv[b];
            tv[b] = tv[a];
            tv[a] = temp1 + temp2;
        }
        for (int i = 0; i < 8; ++i)
            h512[i]+=tv[i];
    }
    // Формирование хеш-значения
    std::string hash;
    hash=compress(h512,8);
    return hash;
}
void Hash::setHashType(const char * _type)
{
    if (strcmp(_type,"md5")==0)  type=HashType::MD5;
    else if (strcmp(_type,"sha256")==0)  type=HashType::SHA256;
    else if (strcmp(_type,"sha512")==0)  type=HashType::SHA512;
}
void  Hash::InitMD5()
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
