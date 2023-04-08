#pragma once

class HotDrink
{
public:
	virtual ~HotDrink() = default;
	virtual void prepare(int volume) = 0;
};
