#include <iostream>

template<typename T>
class Property
{
public:
	Property(T value)
	{
		*this = value;
	}

	operator T()
	{
		return value;
	}

	T operator=(T newValue)
	{
		std::cout << "assignment!\n";
		return value = newValue;
	}

private:
	T value;
};

class Creature
{
public:
	Property<int> strength{10};
	Property<int> agility{4};
};

int main()
{
	Creature c;
	c.strength = 20;
	int x = c.strength;
	std::cout << x << '\n';
	return 0;
}
