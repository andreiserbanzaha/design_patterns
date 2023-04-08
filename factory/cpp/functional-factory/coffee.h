#pragma once

#include "hotdrink.h"

class Coffee : public HotDrink
{
public:
	void prepare(int volume) override;
};
