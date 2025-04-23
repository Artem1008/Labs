#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "trafficlight.h"

class Controller
{
private:
    TrafficLight* trafficlight;
public:
    Controller();
    void run();
};

#endif // CONTROLLER_H
