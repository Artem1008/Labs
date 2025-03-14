#ifndef UKRAINIANHEN_H
#define UKRAINIANHEN_H
#include "hen.h"

class UkrainianHen: public Hen
{
    public:
    std::string country = "Украина";
    int getCountOfEggsPerMonth() override { return 10;}
    std::string getDescription() override;
    virtual ~UkrainianHen(){}
};

#endif // UKRAINIANHEN_H
