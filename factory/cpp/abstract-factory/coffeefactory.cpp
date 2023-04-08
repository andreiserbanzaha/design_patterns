#include "coffeefactory.h"
#include "coffee.h"

std::unique_ptr<HotDrink> CoffeeFactory::make()
{
	return std::unique_ptr<HotDrink>(new Coffee());
}
