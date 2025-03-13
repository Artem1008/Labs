#ifndef RUSSIANHEN_H
#define RUSSIANHEN_H
#include "hen.h"

class RussianHen:public Hen
{
public:
    RussianHen(){};
    std::string country = "Россия";
    int getCountOfEggsPerMonth(){ return 5;}
    std::string getDescription();
    virtual ~RussianHen(){}
};

#endif // RUSSIANHEN_H
