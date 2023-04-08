#include <iostream>
#include <sstream>
#include <string>

class Shape
{
public:
	virtual std::string str() const = 0;
};

class Circle : public Shape
{
public:
	Circle() {}
	Circle(float radius) : _radius{radius} {}

	// Dynamically decorated object won't have access to this API !
	void resize(float factor) { _radius *= factor; }

	std::string str() const override
	{
		std::ostringstream oss;
		oss << "a circle of radius: " << _radius;
		return oss.str();
	}

private:
	float _radius;
};

class Square : public Shape
{
public:
	Square() {}
	Square(float side) : _side{side} {}

	std::string str() const override
	{
		std::ostringstream oss;
		oss << "a square with side of: " << _side;
		return oss.str();
	}

private:
	float _side;
};

class ColoredShape : public Shape
{
public:
	ColoredShape(Shape& shape, std::string const& color)
		: _shape{shape}
		, _color{color}
	{}

	std::string str() const override
	{
		std::ostringstream oss;
		oss << _shape.str() << " and has color: " << _color;
		return oss.str();
	}

private:
	Shape& _shape;
	std::string _color;
};

class TransparentShape : public Shape
{
public:
	TransparentShape(Shape& shape, uint8_t transparency) 
		: _shape{shape}
		, _transparency{transparency}
	{}

	std::string str() const override
	{
		std::ostringstream oss;
		oss << _shape.str() 
			<< " has " 
			<< static_cast<float>(_transparency) / 255.f * 100.f 
			<< "% transparency.";
		return oss.str();
	}

private:
	Shape& _shape;
	uint8_t _transparency;
};

int main()
{
	Square square{5};
	ColoredShape redSquare{square, "red"};
	TransparentShape transparentSquare{redSquare, 51};
	std::cout << square.str() << '\n';
	std::cout << redSquare.str() << '\n';
	std::cout << transparentSquare.str() << '\n';


	return 0;
}
