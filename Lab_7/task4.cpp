#include "CLog.h"

void task4()
{
CLog::PrintMessage(CLog::Priority::Alarm,"AlarmMessage");
CLog::PrintMessage(CLog::Priority::Error,"ErrorMessage");
CLog::PrintMessage(CLog::Priority::Warning,"WarningMessage");
CLog::PrintMessage(CLog::Priority::System,"SystemInformation");
CLog::PrintMessage(CLog::Priority::Service,"ServiceInformation");
CLog::PrintMessage(CLog::Priority::Debugging,"DebuggingInformation");
}
