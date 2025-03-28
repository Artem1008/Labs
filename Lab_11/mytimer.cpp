#include "mytimer.h"

void MyTimer::subTimer(void(*func)())
{
    while(value>0)
    {
        delay(1);
        value-=1;
        PrintTimer();
    }
    func();
}
void MyTimer::CleerConsole(int size)
{
    std::string temp;
    temp.push_back('\r');
    temp.push_back(' ');
    temp.push_back(' ');
    temp.insert(3,size,' ');
    printf("%s",temp.c_str());
}
MyTimer::MyTimer(unsigned long long _value,TypeTime _type):value(_value),type(_type)
{
    tableConvert.insert(std::make_pair(units[second], 1));
    tableConvert.insert(std::make_pair(units[minute], 60));
    tableConvert.insert(std::make_pair(units[hour], 3600));
    tableConvert.insert(std::make_pair(units[day], 86400));
    tableConvert.insert(std::make_pair(units[year], 31536000));
};
char* MyTimer::print()
{
    auto temptime=system_clock::now();
    time = system_clock::to_time_t(temptime);
    return ctime(&time);
}
void MyTimer::PrintTimer()
{
    std::string data;
    getStringTimers();
    data=std::to_string(st.tm_mday)+":"+std::to_string(st.tm_hour)+":"+std::to_string(st.tm_min)+":"+std::to_string(st.tm_sec);
    CleerConsole(data.size());
    printf("\r%d:%d:%d:%d",st.tm_mday,st.tm_hour,st.tm_min,st.tm_sec);
};
void MyTimer::start()
{
    timestart=clock_t::now();
}
void MyTimer::stop()
{
    timestop=clock_t::now();
}
double MyTimer::elapsed() const
{
    if(timestart<timestop)
        return std::chrono::duration_cast<second_t>(timestop - timestart).count();
    else return 0;
}
void MyTimer::delay(int timer) const
{
    std::this_thread::sleep_for(seconds(timer));
}
void MyTimer::addUnits(char _value)
{
    value= ((value/tableConvert[units[type]])*10+(_value-48))*tableConvert[units[type]];
}
void MyTimer::addUnits(int _value,TypeTime _type)
{
    type=_type;
    value= _value*tableConvert[units[type]];
}
void MyTimer::subUnits()
{
    value=((value/tableConvert[units[type]])/10)*tableConvert[units[type]];
}

const std::tm& MyTimer::getStringTimers()
{
    unsigned long long _value=value;
    st.tm_mday=_value/tableConvert[units[day]];
    _value=_value-st.tm_mday*tableConvert[units[day]];
    st.tm_hour=_value/tableConvert[units[hour]];
    _value=_value-st.tm_hour*tableConvert[units[hour]];
    st.tm_min=_value/tableConvert[units[minute]];
    _value=_value-st.tm_min*tableConvert[units[minute]];
    st.tm_sec=_value;
    return st;
}

void MyTimer::startTimers(void(*func)())
{
  std::thread(&MyTimer::subTimer, this,func).join();
}
unsigned long long MyTimer::getUnits()
{
    return value/tableConvert[units[type]];
}
const char* MyTimer::getType()
{
    return units[type];
}
MyTimer& MyTimer::operator++()
{
    type=(type<TypeTime::AllType)?static_cast<TypeTime>(static_cast<int>(type) +1):second;
    return *this;
}
MyTimer& MyTimer::operator--()
{
    type=(type==second)?static_cast<TypeTime>(static_cast<int>(AllType) -1):static_cast<TypeTime>(static_cast<int>(type) -1);
    return *this;
}
MyTimer MyTimer::operator++ (int)
{
    MyTimer copy {*this};
    ++(*this);
    return copy;
}
MyTimer MyTimer::operator-- (int)
{
    MyTimer copy {*this};
    --(*this);
    return copy;
}
MyTimer& MyTimer::operator += (int _index)
{
    type=static_cast<TypeTime>((static_cast<int>(type)+_index)%(static_cast<int>(AllType)-1));
    return *this;
}
MyTimer& MyTimer::operator -= (int _index)
{
    type=static_cast<TypeTime>((static_cast<int>(type)-_index)%(static_cast<int>(AllType)-1));
    return *this;
}

const char* MyTimer::getDayOfWeek(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int q = day;
    int m = month;
    int K = year % 100;
    int J = year / 100;
    int h = ((q + ((13 * (m + 1)) / 5) + K + (K / 4) + (J / 4) - (2 * J)) % 7);
    const char* days[] = { "‘ã¡¡®â ","‚®áªà¥á¥­ì¥", "®­¥¤¥«ì­¨ª", "‚â®à­¨ª", "‘à¥¤ ","—¥â¢¥à£", "ïâ­¨æ "};
    return days[h];
}
