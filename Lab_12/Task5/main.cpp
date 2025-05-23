#include "Model.h"
//Controller
int main()
{
    setlocale(LC_ALL, "");
    //View
    TrafficLight trafficlight;
    //Model
    Model model(&trafficlight);
    model.run();
    return 0;
}
