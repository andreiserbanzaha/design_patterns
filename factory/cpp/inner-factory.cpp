#include <iostream>
#include <cmath>

class Point
{
private:
	Point(double aX, double aY) : x{aX} , y{aY} {}

	class PointFactory
	{
	public:
		static Point newCartesian(double x, double y) { return {x, y}; }
		static Point newPolar(double r, double theta) { return {r * cos(theta), r * sin(theta)}; }
	};

private:
	double x, y;

public:
	static PointFactory factory;

	void print() { std::cout << x << ' ' << y << '\n'; }
};

int main()
{
	auto pc = Point::factory.newCartesian(5.2, 2.5);
	pc.print();

	auto pp = Point::factory.newPolar(5.5, 2.6);
	pp.print();

	return 0;
}
