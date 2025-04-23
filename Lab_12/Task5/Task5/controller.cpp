#include "controller.h"

Controller::Controller()
{
    trafficlight=new TrafficLight();
}

void Controller::run()
{
    int exit=5;
    while(exit)
    {
       std::this_thread::sleep_for(std::chrono::seconds(trafficlight->getState()->getTimeout()));
       trafficlight->SetLight();
       --exit;
    }
}
