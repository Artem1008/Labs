#include "trafficlight.h"

void TrafficLight::SetLight(State *newstate)
{
    if (state ==newstate)
        return;
    delete state;
    state=newstate;
    state->action();
}
YellowState::YellowState(TrafficLight *TL) : State(TL) {}
RedState::RedState(TrafficLight *TL) : State(TL) {}
GreenState::GreenState(TrafficLight *TL) : State(TL) {}

int RedState::getTimeout() const
{
    return RED_TIME;
}
int YellowState::getTimeout() const
{
    return YELLOW_TIME;
}
int GreenState::getTimeout() const
{
    return GREEN_TIME;
}
State::State(TrafficLight *TL) : trafficlight(TL) {}

void RedState::action()
{
    std::wcout << L"Красный свет-СТОЙ!" << std::endl;
}
void YellowState::action()
{
    std::wcout <<L"Желтый свет - Внимание!" << std::endl;
}
void GreenState::action()
{
    std::wcout << L"Зеленый свет - Вперед!" << std::endl;
}

