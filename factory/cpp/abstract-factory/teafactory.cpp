#include "teafactory.h"
#include "tea.h"

std::unique_ptr<HotDrink> TeaFactory::make()
{
	return std::unique_ptr<HotDrink>(new Tea{});
}
