#include <iostream>
#include <cmath>

class Point
{
public:
	static Point newCartesian(double x, double y) 
	{ 
		return {x, y}; 
	}

	static Point newPolar(double r, double theta)
	{
		return {r * cos(theta), r * sin(theta)};
	}

	void print()
	{
		std::cout << x << ' ' << y << '\n';
	}

private:
	Point(double aX, double aY) : x{aX} , y{aY} {}

private:
	double x, y;
};

int main()
{
	auto pc = Point::newCartesian(5.2, 2.5);
	pc.print();

	auto pp = Point::newPolar(5.5, 2.6);
	pp.print();

	return 0;
}
