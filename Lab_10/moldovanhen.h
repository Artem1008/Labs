#ifndef MOLDOVANHEN_H
#define MOLDOVANHEN_H
#include "hen.h"

class MoldovanHen: public Hen
{
    public:
    std::string country = "Молдова";
    int getCountOfEggsPerMonth(){ return 15;}
    std::string getDescription();
     virtual ~MoldovanHen(){}
};

#endif // MOLDOVANHEN_H
