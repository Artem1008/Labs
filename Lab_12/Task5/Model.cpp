#include "controller.h"

Model::Model(TrafficLight* _trafficlight)
{
    if (trafficlight==_trafficlight)
        return;
    delete trafficlight;
    trafficlight=_trafficlight;
}
void Model::run()
{
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
