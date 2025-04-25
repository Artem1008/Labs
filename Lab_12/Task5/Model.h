#ifndef MODEL_H
#define MODEL_H
#include "trafficlight.h"

const int GREEN_TIME = 4;
const int YELLOW_TIME = 1;
const int RED_TIME = 3;

class Controller
{
private:
    TrafficLight* trafficlight=nullptr;
public:
    Controller(TrafficLight*);
    void run();
};

#endif // MODEL_H
