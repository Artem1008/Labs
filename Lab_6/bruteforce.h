#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
#include <string>
extern std::string pass;
class Bruteforce
{
private:
    bool flagNumber;
    bool flagCapital;
    bool flagSymbols;
    char *Capital=new char[27];
    char  *Letters=new char[27];
    char *Number=new char[11];
    char *Symbols=new char[18];

public:
    bool getFlagNumber(){return flagNumber;}
    void setFlagNumber(bool _flag){flagNumber= _flag;}
    bool getFlagCapital(){return flagCapital;}
    void setFlagCapital(bool _flag){flagCapital= _flag;}
    bool getFlagSymbols(){return flagSymbols;}
    void setFlagSymbols(bool _flag){flagSymbols= _flag;}
    Bruteforce();
    std::string RunFind();
};

#endif // BRUTEFORCE_H

