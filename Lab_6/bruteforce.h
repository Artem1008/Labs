/*
 * Класс перебора пароля
*/
#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
#include <QDebug>
#include <string>
extern std::string pass;
class Bruteforce
{
#define MCAPITAL "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define MLETTERS "abcdefghijklmnopqrstuvwxyz"
#define MNUMBER  "0123456789"
#define MSYMBOL  "!\"ь;%:?*()~.,/|\\"
private:
    bool flagNumber;
    bool flagCapital;
    bool flagSymbols;
    int lengthPass;
public:
    bool getFlagNumber(){return flagNumber;}
    void setFlagNumber(bool _flag){flagNumber= _flag;}
    bool getFlagCapital(){return flagCapital;}
    void setFlagCapital(bool _flag){flagCapital= _flag;}
    bool getFlagSymbols(){return flagSymbols;}
    void setFlagSymbols(bool _flag){flagSymbols= _flag;}
    int getLengthPass(){return lengthPass;}
    void setLengthPass(int _lengthPass){lengthPass= _lengthPass;}
    Bruteforce();
    std::string RunFind();
};

#endif // BRUTEFORCE_H

