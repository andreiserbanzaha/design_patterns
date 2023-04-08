#pragma once

#include <memory>
#include "hotdrink.h"

class HotDrinkFactory
{
public:
	virtual std::unique_ptr<HotDrink> make() = 0;
};
