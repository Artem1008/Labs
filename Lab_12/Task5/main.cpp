#include "controller.h"

int main()
{
    setlocale(LC_ALL, "");
    TrafficLight trafficlight;
    Controller controller(&trafficlight);
    controller.run();
    return 0;
}
