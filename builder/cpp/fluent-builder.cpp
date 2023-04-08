#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class HtmlBuilder;

struct HtmlElement
{
	friend HtmlBuilder;

	std::string name;
	std::string text;
	std::vector<HtmlElement> elements;
	const size_t indentSize = 2;

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

private:
	HtmlElement() 
	{}

	HtmlElement(std::string const& aName, std::string const& aText)
		: name{aName}, text{aText}
	{}
};

struct HtmlBuilder 
{
	HtmlElement root;

	HtmlBuilder(std::string const& aRootName)
	{
		root.name = aRootName;
	}

	HtmlBuilder& addChild(std::string const& aChildName, 
			std::string const& aChildText)
	{
		HtmlElement e{aChildName, aChildText};
		root.elements.emplace_back(e);
		return *this;
	}

	std::string str() const
	{
		return root.str();
	}

	operator HtmlElement() const
	{
		return root;
	}
};

int main()
{
	HtmlElement elem = HtmlBuilder("ul")
		.addChild("li", "Hello")
		.addChild("li", "World");

	std::cout << elem.str() << '\n';

	return 0;
}
