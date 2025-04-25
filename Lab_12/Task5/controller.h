#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "trafficlight.h"

const int GREEN_TIME = 4;
const int YELLOW_TIME = 1;
const int RED_TIME = 3;

class Controller
{
private:
    TrafficLight* trafficlight;
public:
    Controller(TrafficLight*);
    void run();
};

#endif // CONTROLLER_H
