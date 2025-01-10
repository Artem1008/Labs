#include "CLog.h"

CLog::CLog()
{

}
void CLog::PrintMessage(int priority,const char* str)
{
    const std::time_t MessageTime = std::time(nullptr);
    char buf[64];
    strftime(buf, sizeof buf, "%c", std::localtime(&MessageTime));
    printf("%s  %s:  %s\n",buf,arr(priority),str);
}
