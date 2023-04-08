#include <iostream>
#include <vector>
#include <string>

class GraphicObject
{
public:
	virtual void draw() = 0;
};

class Circle : public GraphicObject
{
public:
	void draw() override 
	{
		std::cout << "Circle\n";
	}
};

class Group : public GraphicObject
{
public:
	Group(std::string const& name)
		: _name{name}
	{}

	void draw() override
	{
		std::cout << "Group " << _name << " contains: \n";
		for (auto& o : _objects)
		{
			o->draw();
		}
	}

	void addObject(GraphicObject* obj)
	{
		_objects.push_back(obj);
	}

private:
	std::string _name;
	std::vector<GraphicObject*> _objects;
};

int main()
{
	Group g{"root"};
	Circle c1;
	g.addObject(&c1);

	Group sg{"subgroup"};
	Circle c2;
	sg.addObject(&c2);

	g.addObject(&sg);
	g.draw();

	return 0;
}
