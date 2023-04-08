#include <iostream>

class Renderer
{
public:
	virtual void renderCircle(float x, float y, float radius) = 0;
};

class RasterRenderer : public Renderer
{
public:
	void renderCircle(float x, float y, float radius) override
	{
		std::cout << "Raster renderer: " << radius << '\n';
	}
};

class VectorRenderer : public Renderer
{
public:
	void renderCircle(float x, float y, float radius) override
	{
		std::cout << "Vector renderer: " << radius << '\n';
	}
};

class Shape
{
public:
	virtual void draw() = 0;
	virtual void resize(float factor) = 0;

protected:
	Shape(Renderer& renderer)
		: _renderer{renderer}
	{
	}

	Renderer& _renderer; // bridge
};

class Circle : public Shape
{
public:
	Circle(Renderer& renderer, float x, float y, float radius)
		: Shape{renderer} , _x{x}, _y{y}, _radius{radius}
	{
	}

	void draw() override
	{
		_renderer.renderCircle(_x, _y, _radius);
	}

	void resize(float factor) override
	{
		_radius *= factor;
	}

private:
	float _x, _y, _radius;
};


int main()
{
	RasterRenderer rr;
	Circle circle{rr, 5, 5, 5};
	circle.draw();
	circle.resize(2);
	circle.draw();

	return 0;
}
