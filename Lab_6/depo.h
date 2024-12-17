#ifndef DEPO_H
#define DEPO_H
#include "dispatcher.h"
#include "driver.h"

class Depo
{
private:
   Dispatcher *_dispatcher;
   Driver  *_driver;
   Car  *car;
public:
    Depo();
};

#endif // DEPO_H
