#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "trafficlight.h"
#include <thread>

const int GREEN_TIME = 4;
const int YELLOW_TIME = 1;
const int RED_TIME = 3;

class Model
{
private:
    TrafficLight* trafficlight=nullptr;
public:
    Model(TrafficLight*);
    void run();
};

#endif // CONTROLLER_H
