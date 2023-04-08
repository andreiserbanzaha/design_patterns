#include <iostream>
#include <cmath>

class Point
{
public:
	Point(double aX, double aY) : x{aX} , y{aY} {}

	void print()
	{
		std::cout << x << ' ' << y << '\n';
	}

private:
	double x, y;
};

class PointFactory
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
};

int main()
{
	auto pc = PointFactory::newCartesian(5.2, 2.5);
	pc.print();

	auto pp = PointFactory::newPolar(5.5, 2.6);
	pp.print();

	Point p = Point{2.2, 3.3};
	p.print();

	return 0;
}
