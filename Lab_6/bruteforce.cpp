#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
#include <QDebug>
#include <string>
extern std::string pass;
class Bruteforce
{
private:
    bool flagNumber;
    bool flagCapital;
    bool flagSymbols;
    int lengthPass;
    const char *Capital=new char[27]{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    const char *Letters=new char[27]{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
    const char *Number=new char[11]{'0','1','2','3','4','5','6','7','8','9','\0'};
    const char * Symbols=new char[15]{'!',';','%',':','?','*','(',')','~','.',',','/','|','\\','\0'};
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

