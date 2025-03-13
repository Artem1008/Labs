#ifndef HENFACTORY_H
#define HENFACTORY_H
#include <memory>
#include "russianhen.h"
#include "ukrainianhen.h"
#include "moldovanhen.h"
#include "belarusianhen.h"
enum counrtynum
{
    Russian=1,
    Ukrainian,
    Moldovan,
    Belarusian
};

class HenFactory
{
public:
    std::unique_ptr<Hen> getHen(counrtynum index);
    virtual ~HenFactory(){}
};

#endif // HENFACTORY_H
