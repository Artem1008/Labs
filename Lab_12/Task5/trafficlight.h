#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H
#include <string>

const int GREEN_TIME = 40;
const int YELLOW_TIME = 4;
const int RED_TIME = 30;
const int TIMEOUT = 2;
enum ColorType
{
    Red,
    Yellow,
    Green,

};
enum Messages
{
    SetLight,
    Success,
    Fail,
    Start ,
    Shutdown,
    ProblemDetected ,
    TimeOut,
    ModuleFailed,
    StateChanged
};


class TrafficLight
{
private:
    std::string  state;
public:
    TrafficLight();
    int SetLight(ColorType):
};

#endif // TRAFFICLIGHT_H
