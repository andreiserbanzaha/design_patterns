#include<iostream>

class LightSwitch;

class State
{
public:
    virtual void turnOn(LightSwitch*)
    {
        std::cout << "Light is already ON!\n";
    }

    virtual void turnOff(LightSwitch*)
    {
        std::cout << "Light is already OFF!\n";
    }

    virtual ~State() = default;
};

class StateOn : public State
{
public:
    StateOn()
    {
        std::cout << "Light turned ON!\n";
    }

    void turnOff(LightSwitch*) override;
};

class StateOff : public State
{
public:
    StateOff()
    {
        std::cout << "Light turned OFF!\n";
    }

    void turnOn(LightSwitch* ls) override;
};

class LightSwitch
{
public:
    LightSwitch()
    {
        _state = new StateOff{};
    }

    void setState(State* state)
    {
        _state = state;
    }

    void turnOn()
    {
        _state->turnOn(this);
    }

    void turnOff()
    {
        _state->turnOff(this);
    }

private:
    State* _state;
};

void StateOn::turnOff(LightSwitch* ls)
{
    std::cout << "Switching light OFF...\n";
    ls->setState(new StateOff{});
    delete this;
}
void StateOff::turnOn(LightSwitch* ls)
{
    std::cout << "Switching light ON...\n";
    ls->setState(new StateOn{});
    delete this;
}

int main()
{
    LightSwitch ls;
    ls.turnOn();
    ls.turnOff();
    ls.turnOff();

    return 0;
}
