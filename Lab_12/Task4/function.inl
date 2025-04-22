#include <mutex>
#include <vector>
#include <chrono>
#include <iostream>
#include <thread>

std::mutex readMutex;
// Определяем диапазоны символов для каждой кодировки
struct CharRange {
    std::string name;
    std::pair<unsigned int, unsigned int> range1;
    std::pair<unsigned int, unsigned int> range2;
    std::pair<unsigned int, unsigned int> range3;
};

// Массив с диапазонами символов для разных кодировок
union Char16 {
    char bytes[2];
    unsigned short value=0;
};
union Char24 {
    char bytes[3];
    unsigned int value=0;
};
union Char32 {
    char bytes[4];
    unsigned int value=0;
};
std::pair<std::string,int> EncodingUTF8(unsigned char* bufer,size_t size)
{
    CharRange ranges= {"UTF8", {0xD090, 0xD18F}, {32, 126},{0,0}};
    size_t English=0;
    size_t Russian=0;
    size_t None=0;
    Char16 bufer16;
    Char24 bufer24;
    Char32 bufer32;
    size_t countSimvol=0;
    auto timestart=std::chrono::high_resolution_clock::now();
    for(size_t i=0;i<size;)
    {
        if (*bufer<0x80)
        {
            if(*bufer=='\n' || *bufer=='\t' || *bufer=='\r' || *bufer==0x20)
            {
                English+=1;
                Russian+=1;
            }
            else if(ranges.range2.first <= *bufer && *bufer <= ranges.range2.second)
            {
                English+=1;
            }
            ++countSimvol;
            ++bufer;
            ++i;
        }
        else if(*bufer>=0xC2&&*bufer<=0xDF)
        {
            bufer16.bytes[1]=bufer[0];
            bufer16.bytes[0]=bufer[1];

            if(ranges.range1.first <=bufer16.value && bufer16.value <= ranges.range1.second)
            {
                Russian+=1;
            }
            ++countSimvol;
            bufer+=2;
            i+=2;
        }
        else if(*bufer>=0xE0&&*bufer<=0xF0)
        {
            bufer24.bytes[2]=bufer[0];
            bufer24.bytes[1]=bufer[1];
            bufer24.bytes[0]=bufer[2];
            None+=1;
            bufer+=3;
            i+=3;
            ++countSimvol;
        }
        else
        {
            bufer32.bytes[3]=bufer[0];
            bufer32.bytes[2]=bufer[1];
            bufer32.bytes[1]=bufer[2];
            bufer32.bytes[0]=bufer[3];
            None+=1;
            bufer+=4;
            ++countSimvol;
        }

    }
     auto timeend=std::chrono::high_resolution_clock::now();
    readMutex.lock();
    std::wcout <<L"Поток номер "<<std::this_thread::get_id()<<L" сработал за "<<std::chrono::duration_cast<std::chrono::nanoseconds>(timeend - timestart).count()<<L" наносек \n";
    readMutex.unlock();
    if (English>Russian&& English>1&&English>None) return std::make_pair("English "+ranges.name,English*100/countSimvol);
    if (Russian>English&& Russian>1&&Russian>None) return std::make_pair("Russian "+ranges.name,Russian*100/countSimvol);
    return std::make_pair(ranges.name,0);
}
std::pair<std::string,int> EncodingASCII(unsigned char* bufer,size_t size)
{
    CharRange ranges= {"ASCII",  {0, 0}, {32, 126},{0,0}};
    size_t English=0;
    size_t Russian=0;
    size_t None=0;
    auto timestart=std::chrono::high_resolution_clock::now();
    for(size_t i=0;i<size;++bufer, ++i)
    {
            if(*bufer=='\n' || *bufer=='\t' || *bufer=='\r' || *bufer==0x20)
            {
                English+=1;
                Russian+=1;
            }
            else if(ranges.range2.first <= *bufer && *bufer <= ranges.range2.second)
            {
                English+=1;
            }
            else if(ranges.range1.first <= *bufer && *bufer <= ranges.range1.second)
            {
                Russian+=1;
            }
    }
    auto timeend=std::chrono::high_resolution_clock::now();
    readMutex.lock();
    std::wcout <<L"Поток номер "<<std::this_thread::get_id()<<L" сработал за "<<std::chrono::duration_cast<std::chrono::nanoseconds>(timeend - timestart).count()<<L" наносек \n";
    readMutex.unlock();
    if (English>Russian&& English>1&&English>None) return std::make_pair("English "+ranges.name,English*100/size);
    if (Russian>English&& Russian>1&&Russian>None) return std::make_pair("Russian "+ranges.name,Russian*100/size);
    return std::make_pair(ranges.name,0);
}
std::pair<std::string,int> EncodingCP1251(unsigned char* bufer,size_t size)
{
    CharRange ranges= {"CP1251", {192, 255}, {32, 126},{0,0}};
    size_t English=0;
    size_t Russian=0;
    size_t None=0;
    auto timestart=std::chrono::high_resolution_clock::now();
    for(size_t i=0;i<size;++bufer, ++i)
    {
            if(*bufer=='\n' || *bufer=='\t' || *bufer=='\r' || *bufer==0x20)
            {
                English+=1;
                Russian+=1;
            }
            else if(ranges.range2.first <= *bufer && *bufer <= ranges.range2.second)
            {
                English+=1;
            }
            else if(ranges.range1.first <= *bufer && *bufer <= ranges.range1.second)
            {
                Russian+=1;
            }
    }
    auto timeend=std::chrono::high_resolution_clock::now();
    readMutex.lock();
    std::wcout <<L"Поток номер "<<std::this_thread::get_id()<<L" сработал за "<<std::chrono::duration_cast<std::chrono::nanoseconds>(timeend - timestart).count()<<L" наносек \n";
    readMutex.unlock();
    if (English>Russian&& English>1&&English>None) return std::make_pair("English "+ranges.name,English*100/size);
    if (Russian>English&& Russian>1&&Russian>None) return std::make_pair("Russian "+ranges.name,Russian*100/size);
    return std::make_pair(ranges.name,0);
}
std::pair<std::string,int> EncodingCP866(unsigned char* bufer,size_t size)
{
    CharRange ranges= {"CP866", {128, 175}, {32, 126},{224,241}};
    size_t English=0;
    size_t Russian=0;
    size_t None=0;
    auto timestart=std::chrono::high_resolution_clock::now();
    for(size_t i=0;i<size;++bufer, ++i)
    {
        if(*bufer=='\n' || *bufer=='\t' || *bufer=='\r' || *bufer==0x20)
        {
            English+=1;
            Russian+=1;
        }
        else if(ranges.range2.first <= *bufer && *bufer <= ranges.range2.second)
        {
            English+=1;
        }
        else if((ranges.range1.first <= *bufer && *bufer <= ranges.range1.second) ||
                (ranges.range3.first <= *bufer && *bufer <= ranges.range3.second))
        {
            Russian+=1;
        }
    }
    auto timeend=std::chrono::high_resolution_clock::now();
    readMutex.lock();
    std::wcout <<L"Поток номер "<<std::this_thread::get_id()<<L" сработал за "<<std::chrono::duration_cast<std::chrono::nanoseconds>(timeend - timestart).count()<<L" наносек \n";
    readMutex.unlock();
    if (English>Russian&& English>1&&English>None) return std::make_pair("English "+ranges.name,English*100/size);
    if (Russian>English&& Russian>1&&Russian>None) return std::make_pair("Russian "+ranges.name,Russian*100/size);
    return std::make_pair(ranges.name,0);
}
std::pair<std::string,int> EncodingISO88595(unsigned char* bufer,size_t size)
{
    CharRange ranges= {"ISO8859",  {176, 241}, {32, 126},{0,0}};
    size_t English=0;
    size_t Russian=0;
    size_t None=0;
    auto timestart=std::chrono::high_resolution_clock::now();
    for(size_t i=0;i<size;++bufer, ++i)
    {
            if(*bufer=='\n' || *bufer=='\t' || *bufer=='\r' || *bufer==0x20)
            {
                English+=1;
                Russian+=1;
            }
            else if(ranges.range2.first <= *bufer && *bufer <= ranges.range2.second)
            {
                English+=1;
            }
            else if(ranges.range1.first <= *bufer && *bufer <= ranges.range1.second)
            {
                Russian+=1;
            }
    }
    auto timeend=std::chrono::high_resolution_clock::now();
    readMutex.lock();
    std::wcout <<L"Поток номер "<<std::this_thread::get_id()<<L" сработал за "<<std::chrono::duration_cast<std::chrono::nanoseconds>(timeend - timestart).count()<<L" наносек \n";
    readMutex.unlock();
    if (English>Russian&& English>1&&English>None) return std::make_pair("English "+ranges.name,English*100/size);
    if (Russian>English&& Russian>1&&Russian>None) return std::make_pair("Russian "+ranges.name,Russian*100/size);
    return std::make_pair(ranges.name,0);
}
std::pair<std::string,int> EncodingKOI8R(unsigned char* bufer,size_t size)
{
    CharRange ranges= {"KOI8R", {192, 255}, {32, 126},{0,0}};
    size_t English=0;
    size_t Russian=0;
    size_t None=0;
    auto timestart=std::chrono::high_resolution_clock::now();
    for(size_t i=0;i<size;++bufer, ++i)
    {
            if(*bufer=='\n' || *bufer=='\t' || *bufer=='\r' || *bufer==0x20)
            {
                English+=1;
                Russian+=1;
            }
            else if(ranges.range2.first <= *bufer && *bufer <= ranges.range2.second)
            {
                English+=1;
            }
            else if(ranges.range1.first <= *bufer && *bufer <= ranges.range1.second)
            {
                Russian+=1;
            }
    }
    auto timeend=std::chrono::high_resolution_clock::now();
    readMutex.lock();
    std::wcout <<L"Поток номер "<<std::this_thread::get_id()<<L" сработал за "<<std::chrono::duration_cast<std::chrono::nanoseconds>(timeend - timestart).count()<<L" наносек \n";
    readMutex.unlock();
    if (English>Russian&& English>1&&English>None) return std::make_pair("English "+ranges.name,English*100/size);
    if (Russian>English&& Russian>1&&Russian>None) return std::make_pair("Russian "+ranges.name,Russian*100/size);
    return std::make_pair(ranges.name,0);
}
std::pair<std::string,int> EncodingUTF16LE(unsigned char* bufer,size_t size)
{
    CharRange ranges= {"UTF16LE",{0x0410, 0x044F}, {32, 126},{0,0}};
    size_t English=0;
    size_t Russian=0;
    size_t None=0;
    Char16 bufer16;
    size_t countSimvol=0;
    auto timestart=std::chrono::high_resolution_clock::now();
    for(size_t i=0;i<size;bufer+=2,i+=2)
    {
        bufer16.bytes[1]=bufer[0];
        bufer16.bytes[0]=bufer[1];

        if(bufer16.value=='\n' || bufer16.value=='\t' || bufer16.value=='\r' || bufer16.value==0x20)
        {
            English+=1;
            Russian+=1;
        }
        else if(ranges.range2.first <= bufer16.value && bufer16.value <= ranges.range2.second)
        {
            English+=1;
        }
        else if(ranges.range1.first <= bufer16.value && bufer16.value <= ranges.range1.second)
        {
            Russian+=1;
        }
         ++countSimvol;
        bufer+=2;
        i+=2;
    }
    auto timeend=std::chrono::high_resolution_clock::now();
    readMutex.lock(); 
    std::wcout <<L"Поток номер "<<std::this_thread::get_id()<<L" сработал за "<<std::chrono::duration_cast<std::chrono::nanoseconds>(timeend - timestart).count()<<L" наносек \n";
    readMutex.unlock();
    if (English>Russian&& English>1&&English>None) return std::make_pair("English "+ranges.name,English*100/countSimvol);
    if (Russian>English&& Russian>1&&Russian>None) return std::make_pair("Russian "+ranges.name,Russian*100/countSimvol);
    return std::make_pair(ranges.name,0);
}
std::pair<std::string,int> EncodingUTF16BE(unsigned char* bufer,size_t size)
{
    CharRange ranges= {"UTF16BE",{0x0410, 0x044F}, {32, 126},{0,0}};
    size_t English=0;
    size_t Russian=0;
    size_t None=0;
    Char16 bufer16;
    size_t countSimvol=0;
    auto timestart=std::chrono::high_resolution_clock::now();
    for(size_t i=0;i<size;bufer+=2,i+=2)
    {
        bufer16.bytes[1]=bufer[1];
        bufer16.bytes[0]=bufer[0];

        if(bufer16.value=='\n' || bufer16.value=='\t' || bufer16.value=='\r' || bufer16.value==0x20)
        {
            English+=1;
            Russian+=1;
        }
        else if(ranges.range2.first <= bufer16.value && bufer16.value <= ranges.range2.second)
        {
            English+=1;
        }
        else if(ranges.range1.first <= bufer16.value && bufer16.value <= ranges.range1.second)
        {
            Russian+=1;
        }
         ++countSimvol;
        bufer+=2;
        i+=2;
    }
    auto timeend=std::chrono::high_resolution_clock::now();
    readMutex.lock(); 
    std::wcout <<L"Поток номер "<<std::this_thread::get_id()<<L" сработал за "<<std::chrono::duration_cast<std::chrono::nanoseconds>(timeend - timestart).count()<<L" наносек \n";
    readMutex.unlock();
    if (English>Russian&& English>1&&English>None) return std::make_pair("English "+ranges.name,English*100/countSimvol);
    if (Russian>English&& Russian>1&&Russian>None) return std::make_pair("Russian "+ranges.name,Russian*100/countSimvol);
    return std::make_pair(ranges.name,0);
}
std::pair<std::string,int> EncodingUTF32LE(unsigned char* bufer,size_t size)
{
    CharRange ranges= {"UTF32LE",{0x00000410, 0x0000044F}, {32, 126},{0,0}};
    size_t English=0;
    size_t Russian=0;
    size_t None=0;
    Char32 bufer32;
    size_t countSimvol=0;
    auto timestart=std::chrono::high_resolution_clock::now();
    for(size_t i=0;i<size;bufer+=4,i+=4)
    {
        bufer32.bytes[3]=bufer[0];
        bufer32.bytes[2]=bufer[1];
        bufer32.bytes[1]=bufer[2];
        bufer32.bytes[0]=bufer[3];

        if(bufer32.value=='\n' || bufer32.value=='\t' || bufer32.value=='\r' || bufer32.value==0x20)
        {
            English+=1;
            Russian+=1;
        }
        else if(ranges.range2.first <= bufer32.value && bufer32.value <= ranges.range2.second)
        {
            English+=1;
        }
        else if(ranges.range1.first <= bufer32.value && bufer32.value <= ranges.range1.second)
        {
            Russian+=1;
        }
         ++countSimvol;
        bufer+=2;
        i+=2;
    }
    auto timeend=std::chrono::high_resolution_clock::now();
    readMutex.lock();
    std::wcout <<L"Поток номер "<<std::this_thread::get_id()<<L" сработал за "<<std::chrono::duration_cast<std::chrono::nanoseconds>(timeend - timestart).count()<<L" наносек \n";
    readMutex.unlock();
    if (English>Russian&& English>1&&English>None) return std::make_pair("English "+ranges.name,English*100/countSimvol);
    if (Russian>English&& Russian>1&&Russian>None) return std::make_pair("Russian "+ranges.name,Russian*100/countSimvol);
    return std::make_pair(ranges.name,0);
}
std::pair<std::string,int> EncodingUTF32BE(unsigned char* bufer,size_t size)
{
    CharRange ranges= {"UTF32BE",{0x00000410, 0x0000044F}, {32, 126},{0,0}};
    size_t English=0;
    size_t Russian=0;
    size_t None=0;
    Char32 bufer32;
    size_t countSimvol=0;
    auto timestart=std::chrono::high_resolution_clock::now();
    for(size_t i=0;i<size;bufer+=4,i+=4)
    {
        bufer32.bytes[3]=bufer[3];
        bufer32.bytes[2]=bufer[2];
        bufer32.bytes[1]=bufer[1];
        bufer32.bytes[0]=bufer[0];

        if(bufer32.value=='\n' || bufer32.value=='\t' || bufer32.value=='\r' || bufer32.value==0x20)
        {
            English+=1;
            Russian+=1;
        }
        else if(ranges.range2.first <= bufer32.value && bufer32.value <= ranges.range2.second)
        {
            English+=1;
        }
        else if(ranges.range1.first <= bufer32.value && bufer32.value <= ranges.range1.second)
        {
            Russian+=1;
        }
         ++countSimvol;
        bufer+=2;
        i+=2;
    }
    auto timeend=std::chrono::high_resolution_clock::now();
    readMutex.lock(); 
    std::wcout <<L"Поток номер "<<std::this_thread::get_id()<<L" сработал за "<<std::chrono::duration_cast<std::chrono::nanoseconds>(timeend - timestart).count()<<L" наносек \n";
    readMutex.unlock();
    if (English>Russian&& English>1&&English>None) return std::make_pair("English "+ranges.name,English*100/countSimvol);
    if (Russian>English&& Russian>1&&Russian>None) return std::make_pair("Russian "+ranges.name,Russian*100/countSimvol);
    return std::make_pair(ranges.name,0);
}
std::pair<std::string,int> EncodingUCS2(unsigned char* bufer,size_t size)
{
    CharRange ranges= {"UCS2", {0x0410, 0x044F}, {32, 126},{0,0}};
    size_t English=0;
    size_t Russian=0;
    size_t None=0;
    auto timestart=std::chrono::high_resolution_clock::now();
    for(size_t i=0;i<size;++bufer, ++i)
    {
            if(*bufer=='\n' || *bufer=='\t' || *bufer=='\r' || *bufer==0x20)
            {
                English+=1;
                Russian+=1;
            }
            else if(ranges.range2.first <= *bufer && *bufer <= ranges.range2.second)
            {
                English+=1;
            }
            else if(ranges.range1.first <= *bufer && *bufer <= ranges.range1.second)
            {
                Russian+=1;
            }
    }
    auto timeend=std::chrono::high_resolution_clock::now();
    readMutex.lock();
    std::wcout <<L"Поток номер "<<std::this_thread::get_id()<<L" сработал за "<<std::chrono::duration_cast<std::chrono::nanoseconds>(timeend - timestart).count()<<L" наносек \n";
    readMutex.unlock();
    if (English>Russian&& English>1&&English>None) return std::make_pair("English "+ranges.name,English*100/size);
    if (Russian>English&& Russian>1&&Russian>None) return std::make_pair("Russian "+ranges.name,Russian*100/size);
    return std::make_pair("None",0);
}
