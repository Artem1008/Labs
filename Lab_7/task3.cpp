#include <iostream>

class LoggerGuard
{
private:
    LoggerGuard();
    std::string Message;
    std::ostream& Out;
public:
    LoggerGuard(const std::string& message, std::ostream& out = std::cout):Message(message),Out(out){};
    void print()
    {
     Out<<Message;
    };
};
int SomeFunction()
{
   return 0;
}
int SomeOtherFunction()
{
   return 0;
}
int FinalFunction()
{
   return 0;
}
//вместо печати строки раздуваем программу ещё на дополнительный класс который опять таки надо дублировать
//возможно в ТЗ имелось введу что то другое
int Function()
{
    LoggerGuard logger("Function completed");
    int value = 1;
    try {
        value = SomeFunction();
        if (value == 0) {
            logger.print();
            return value;
        }
        value = SomeOtherFunction();
        if (value == 0) {
            logger.print();
            return value;
        }
        value = FinalFunction(); // might throw an exception
    } catch (...) {
        logger.print();
        throw; // throws the exception further.
    }
    logger.print();
    return value;
}
void task3()
{
    Function();
}
