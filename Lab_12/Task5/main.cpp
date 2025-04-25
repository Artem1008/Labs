#include "Model.h"

int main()
{
    setlocale(LC_ALL, "");
    TrafficLight trafficlight;
    Model model(&trafficlight);
    model.run();
    return 0;
}
