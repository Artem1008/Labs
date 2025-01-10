#ifndef YOURCLASS_H
#define YOURCLASS_H
#include <ctime>
#include <iomanip>
#include <iostream>
#define arr(x) x==1? "Alarm":(x==2? "Error": (x==3? "Warning": (x==4? "System": (x==5? "Service": (x==6? "Debugging":"NoName")))))

class CLog
{

public:
    enum Priority{ Alarm,Error,Warning,System,Service,Debugging,None};
    static int m_nLevel;
    CLog();
    static void PrintMessage(int priority,const char* str);
};
#endif // YOURCLASS_H
