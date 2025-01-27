#ifndef YOURCLASS_H
#define YOURCLASS_H
#include <ctime>
#include <iomanip>
#include <iostream>
#define arr(x) x==1? "Alarm":(x==2? "Error": (x==3? "Warning": (x==4? "System": (x==5? "Service": (x==6? "Debugging":"NoName")))))

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
