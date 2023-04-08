#include <iostream>

#include "drinkfactory.h"

int main()
{
	DrinkFactory df;
	auto c = df.make_drink("coffee");

	return 0;
}
