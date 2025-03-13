#ifndef UKRAINIANHEN_H
#define UKRAINIANHEN_H
#include "hen.h"

class UkrainianHen: public Hen
{
    public:
    std::string country = "Украина";
    int getCountOfEggsPerMonth(){ return 10;}
    std::string getDescription();
    virtual ~UkrainianHen(){}
};

#endif // UKRAINIANHEN_H
