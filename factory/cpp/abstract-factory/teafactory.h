#pragma once

#include "hotdrinkfactory.h"
#include "hotdrink.h"

class TeaFactory : public HotDrinkFactory
{
public:
	std::unique_ptr<HotDrink> make() override;
};

