#ifndef YOURCLASS_H
#define YOURCLASS_H
#include <ctime>
#include <iomanip>
#include <iostream>
#define arr(x) x==0x1? "Alarm":(x==0x2? "Error": (x==0x4? "Warning": (x==0x8? "Debugging": (x==0x10? "System": (x==0x20? "Service":"NoName")))))


class CLog
{
public:
    CLog();
    static int Level;
    enum Priority{ Alarm=0x1,Error=0x2,Warning=0x4,Debugging=0x8,System=0x10,Service=0x20,All=0x3F};
    static void PrintMessage(int,const char*);
    static void SetLevel(int);
    static bool CheckLevel(int);
};

#endif // YOURCLASS_H
