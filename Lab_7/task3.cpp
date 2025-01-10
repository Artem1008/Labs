
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
//����� ���� ��ப� ࠧ�㢠�� �ணࠬ�� ��� �� �������⥫�� �����, � ���ࠢ�� ���� ����ﭭ� ��뢠�� ��⮤ �� ����, �� �⮬ �������� ᮮ�饭�� �� ��������
//�������� � �� ������� ����� �� � ��㣮�
int Function()
{
    LoggerGuard logger("Function completed\n");
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
    //���� ��ன ��ਠ�� �᫨ ���⠥� ���� � ⮦� � ����� ᤥ���� ������
    LoggerGuard logger("Function completed\n");
    Function();
    logger.print();
}
