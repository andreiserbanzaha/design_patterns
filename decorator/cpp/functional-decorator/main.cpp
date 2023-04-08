#include <iostream>
#include <string>
#include <functional>

// -----------------------------------------------------------------------------
class Logger
{
public:
    Logger(std::function<void()> const& func, std::string const& name)
        : _func{func}
        , _name{name}
    {}

    void operator() ()
    {
        std::cout << "Entering " << _name << '\n';
        _func();
        std::cout << "Exiting " << _name << '\n';
    }

private:
    std::function<void()> _func;
    std::string _name;
};

// -----------------------------------------------------------------------------
template <typename Func>
class TLogger
{
public:
    TLogger(Func const& func, std::string const& name)
        : _func{func}
        , _name{name}
    {}

    void operator() ()
    {
        std::cout << "Entering " << _name << '\n';
        _func();
        std::cout << "Exiting " << _name << '\n';
    }

private:
    Func _func;
    std::string _name;
};

template <typename Func>
TLogger<Func> makeLogger(Func func, std::string const& name)
{
    return TLogger<Func>{func, name};
}

// -----------------------------------------------------------------------------
double add(double a, double b)
{
    double c = a + b;
    std::cout << a << " + " << b << " = " << c << '\n';
    return c;
}

// needed for partial template specialization
template <typename>
class RLogger;

// partial template specialization
template <typename R, typename ... Args>
class RLogger<R(Args...)>
{
public:
    RLogger(std::function<R(Args...)> const& func, std::string const& name)
        : _func{func}
        , _name{name}
    {}

    R operator() (Args ... args)
    {
        std::cout << "Entering " << _name << '\n';
        R result = _func(args...);
        std::cout << "Exiting " << _name << '\n';
        return result;
    }

private:
    std::function<R(Args...)> _func;
    std::string _name;
};

template <typename R, typename ...Args>
auto makeRLogger(R(*func)(Args...), std::string const& name)
{
    return RLogger<R(Args...)>({
        std::function<R(Args...)>(func),
        name
    });
}

int main()
{
    // Logger
    Logger([](){ std::cout << "Hello\n";}, "HelloFunction")();
    std::cout << '\n';

    // TLogger with template argument
    TLogger<std::function<void()>>([](){
        std::cout << "Hello\n";
    }, "THelloFunction")();
    std::cout << '\n';

    // TLogger using makeLogger
    auto tLogger = makeLogger([](){
        std::cout << "Hello\n";
    }, "makeHelloFunction");
    tLogger();
    std::cout << '\n';

    // RLogger
    auto loggedAdd = makeRLogger(add, "add");
    auto res = loggedAdd(2, 3);
    std::cout << "result = " << res << '\n';

    return 0;
}
