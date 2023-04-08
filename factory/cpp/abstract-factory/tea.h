#pragma once

#include "hotdrink.h"

class Tea : public HotDrink
{
public:
	void prepare(int volume) override;
};
