#pragma once

#include <map>
#include <memory>
#include <string>

#include "hotdrink.h"
#include "hotdrinkfactory.h"
#include "coffeefactory.h"
#include "teafactory.h"

class DrinkFactory
{
public:
    DrinkFactory()
    {
        factories["coffee"] = std::unique_ptr<CoffeeFactory>(new CoffeeFactory);
        factories["tea"] = std::unique_ptr<TeaFactory>(new TeaFactory);
    }

    std::unique_ptr<HotDrink> make_drink(std::string const& name)
    {
        auto drink = factories[name]->make();
        drink->prepare(200);
        return drink;
    }

private:
    std::map<std::string, std::unique_ptr<HotDrinkFactory>> factories;
};
