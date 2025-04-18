#ifndef MYTIMER_H
#define MYTIMER_H
#include <chrono>
#include <iostream>
#include <thread>
#include <map>
#include <vector>
#include <conio.h>

#define ENTER 13
#define ESC 27
#define KEY_UP 72
#define KEY_DOWN 80
#define BACKSPACE 8

using namespace std::chrono;
enum TypeTime
{
    second,
    minute,
    hour,
    day,
    year,
    AllType
};

class MyTimer
{
private:
    const char* units[AllType]={"секунд", "минут","часов","дней","лет"};
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;
    std::map<std::string,unsigned int> tableConvert;
    unsigned long long value;
    struct tm st;
    std::time_t time=0;
    time_point<clock_t> timestart;
    time_point<clock_t> timestop;
    TypeTime type;
    void subTimer(void(*func)());
    void CleerConsole(int size);
public:
    MyTimer(unsigned long long _value=0,TypeTime _index=second);
    char* print();
    void start();
    void stop();
    double elapsed() const;
    void delay(int timer) const;
    void addUnits(char _value);
    void addUnits(int _value,TypeTime);
    void subUnits();
    const std::tm& getStringTimers();
    void startTimers(void(*func)());
    void stopTimers();
    unsigned long long getUnits();
    void PrintTimer();
    const char* getType();
    MyTimer& operator++();
    MyTimer& operator--();
    MyTimer operator++ (int);
    MyTimer operator-- (int);
    MyTimer& operator += (int _index);
    MyTimer& operator -= (int _index);
    const char* getDayOfWeek(int day, int month, int year);
    virtual ~MyTimer(){};
};

#endif // MYTIMER_H
