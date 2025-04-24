#include "controller.h"
#include <thread>
#include <functional>
Controller::Controller()
{
    trafficlight=new TrafficLight();
}

void Controller::run()
{
    int error;
    int exit=2;
    std::thread t(&TrafficLight::On, trafficlight);
    t.detach();
    while(exit)
    {
      trafficlight->SetLight(Red);
      std::this_thread::sleep_for(std::chrono::seconds(RED_TIME));
      trafficlight->SetLight(Yellow);
      std::this_thread::sleep_for(std::chrono::seconds(YELLOW_TIME));
      trafficlight->SetLight(Green);
      std::this_thread::sleep_for(std::chrono::seconds(GREEN_TIME));
      trafficlight->SetLight(Yellow);
      std::this_thread::sleep_for(std::chrono::seconds(YELLOW_TIME));
       --exit;
    }
    trafficlight->OFF();
}
