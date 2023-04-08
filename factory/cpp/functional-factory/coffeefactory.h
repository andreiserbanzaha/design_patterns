#pragma once

#include "hotdrinkfactory.h"

class CoffeeFactory : public HotDrinkFactory
{
public:
	std::unique_ptr<HotDrink> make() override;
};

