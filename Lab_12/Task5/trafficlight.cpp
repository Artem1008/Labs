#include "trafficlight.h"

std::mutex mx;
int TrafficLight::SetLight(ColorType type)
{
    if (state ==arrstate[type])
        return ProblemDetected;
    FlashLight(5);
    state=arrstate[type];
    return Set;
}
void TrafficLight::FlashLight(int count)
{
    for(int i=0;i<count;++i)
    {
        mx.lock();
        std::wcout << state->getColor()<<L" Внимание!" << std::endl;
        mx.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
int TrafficLight::OFF()
{
    isRunning=false;
    mx.lock();
    std::wcout<<L"Светофор выключен"<<'\n';
    mx.unlock();
    return Shutdown;
}
int TrafficLight::On()
{
    mx.lock();
    std::wcout<<L"Светофор включен"<<'\n';
    mx.unlock();
    State* oldStatus=nullptr;
    try
    {
        isRunning=true;
        while(isRunning)
        {
            if (Error){
                mx.lock();
                std::wcout<<L"Ошибка светофора"<<'\n';
                mx.unlock();
                state=arrstate[0];
                FlashLight(1);
            }
            else
            {
                if(state!=oldStatus)
                {
                    state->action();
                    oldStatus=state;
                }
            }
        }
    }
    catch (...)
    {
        return Fail;
    }
    return Shutdown;
}

void RedState::action()
{
    mx.lock();
    std::wcout << color<<L" свет!" << std::endl;
    mx.unlock();
}
void YellowState::action()
{
    mx.lock();
    std::wcout << color<<L" свет" << std::endl;
    mx.unlock();
}
void GreenState::action()
{
    mx.lock();
    std::wcout << color<< L" свет" << std::endl;
    mx.unlock();
}


std::wstring State::getColor()
{
    return color;
}
