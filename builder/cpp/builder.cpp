#include <iostream>
#include <string>
#include <vector>
#include <sstream>

struct HtmlElement
{
	std::string name;
	std::string text;
	std::vector<HtmlElement> elements;
	const size_t indentSize = 2;

	HtmlElement() 
	{}

	HtmlElement(std::string const& aName, std::string const& aText)
		: name{aName},
		text{aText}
	{}

	std::string str(int indent = 0) const
	{
		std::ostringstream oss;
		std::string i(indentSize * indent, ' ');
		oss << i << '<' << name << ">\n";
		if (text.size() > 0)
			oss << std::string(indentSize * (indent + 1), ' ') << text << '\n';
		for (auto const& e : elements)
			oss << e.str(indent + 1);
		oss << i << "</" << name << ">\n";
		return oss.str();
	}
};

struct HtmlBuilder 
{
	HtmlElement root;

	HtmlBuilder(std::string aRootName)
	{
		root.name = aRootName;
	}

	void addChild(std::string const& aChildName, std::string const& aChildText)
	{
		HtmlElement e{aChildName, aChildText};
		root.elements.emplace_back(e);
	}

	std::string str() const
	{
		return root.str();
	}
};

int main()
{
	HtmlBuilder builder{"ul"};
	builder.addChild("li", "Hello");
	builder.addChild("li", "World");
	std::cout << builder.str() << '\n';

	return 0;
}
