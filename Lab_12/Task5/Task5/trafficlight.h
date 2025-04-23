#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include "state.h"


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
const int GREEN_TIME = 40;
const int YELLOW_TIME = 4;
const int RED_TIME = 30;

class TrafficLight;

class State {
protected:
    TrafficLight* trafficlight;
public:
    virtual ~State() {}
    explicit State(TrafficLight* TL);
    virtual void action() = 0;
    virtual int getTimeout() const = 0;
};

class YellowState : public State {
public:
    YellowState(TrafficLight *TL);
    void action() override;
    int getTimeout() const override;
};
class GreenState : public State {
public:
    GreenState(TrafficLight *TL);
    void action() override;
    int getTimeout() const override;
};
class RedState: public State {
public:
    RedState(TrafficLight *TL);
    void action() override;
    int getTimeout() const override;
};

class TrafficLight
{
private:
    State* state;
    State* yellowstate;
    State* greenstate;
    State* redstate;
    bool isRunning = false;
public:
    TrafficLight()
    {
        yellowstate=new YellowState(this);
        greenstate=new GreenState(this);
        redstate= new RedState(this);
        state=yellowstate;
        state->action();
    }
    State* getState();
    void SetLight(State *newstate );
    ~TrafficLight()
    {
        delete yellowstate;
        delete state;
        delete greenstate;
        delete redstate;
    }
};

#endif // TRAFFICLIGHT_H
