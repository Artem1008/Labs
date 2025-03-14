#ifndef BELARUSIANHEN_H
#define BELARUSIANHEN_H
#include "hen.h"

class BelarusianHen: public Hen
{
    public:
    std::string country = "Белорусия";
    int getCountOfEggsPerMonth() override { return 20;}
    std::string getDescription() override ;
    virtual ~BelarusianHen(){}
};

#endif // BELARUSIANHEN_H
