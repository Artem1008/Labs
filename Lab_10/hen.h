#ifndef HEN_H
#define HEN_H
#include <string>

class Hen
{
public:
    virtual int getCountOfEggsPerMonth()=0;
    virtual std::string getDescription(){return "� ���� ";}
    virtual ~Hen(){}
};

#endif // HEN_H
