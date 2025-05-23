#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H
#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include <chrono>

enum ColorType
{
    Yellow,
    Red,
    Green,
};
enum Messages
{
    Set,
    Success,
    Fail,
    Start ,
    Shutdown,
    ProblemDetected ,
    TimeOut,
    ModuleFailed,
    StateChanged
};


class TrafficLight;

class State {
protected:
    std::wstring color;
public:
    virtual ~State() {}
    explicit State(){};
    virtual std::wstring getColor();
    virtual void action() = 0;
};

class YellowState : public State {
public:
    YellowState()
    {
        color=L"Желтый";
    };
    void action() override;
};
class GreenState : public State {
public:
    GreenState()
    {
        color=L"Зеленый";
    };
    void action() override;
};
class RedState: public State {
public:
    RedState()
    {
        color=L"Красный";
    };
    void action() override;
};

class TrafficLight
{
private:
    State* state;
    State* arrstate[3];
    bool isRunning = false;
    bool Error=false;
    void FlashLight(int);
public:
    TrafficLight()
    {
        arrstate[0]=new YellowState;
        arrstate[1]=new RedState;
        arrstate[2]=new GreenState;
        state=arrstate[0];
        state->action();
    }
    int On();
    int OFF();
    State* getState();
    int SetLight(ColorType);
    ~TrafficLight()
    {
        delete state;
    }
};

#endif // TRAFFICLIGHT_H
