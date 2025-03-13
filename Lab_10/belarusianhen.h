#ifndef BELARUSIANHEN_H
#define BELARUSIANHEN_H
#include "hen.h"

class BelarusianHen: public Hen
{
    public:
    std::string country = "Белорусия";
    int getCountOfEggsPerMonth(){ return 20;}
    std::string getDescription();
    virtual ~BelarusianHen(){}
};

#endif // BELARUSIANHEN_H
