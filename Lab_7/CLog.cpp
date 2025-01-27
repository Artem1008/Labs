#include "CLog.h"
int CLog::Level;
CLog::CLog()
{

}
void CLog::PrintMessage(int priority,const char* str)
{
 if (CheckLevel(priority))
    {
    const std::time_t MessageTime = std::time(nullptr);
    char buf[64];
    strftime(buf, sizeof buf, "%c", std::localtime(&MessageTime));
    printf("%s  %s:  %s\n",buf,arr(priority),str);
    }
}
void CLog::SetLevel(int _level)
{
    Level=_level;
}
bool CLog::CheckLevel(int _level)
{
    return (_level&Level);
}
