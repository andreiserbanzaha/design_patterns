#include <map>
#include <string>
#include <functional>

class FunctionalFactory
{
public:
	FunctionalFactory()
	{
		factories["tea"] = [] {
			auto tea = std::unique_ptr<Tea>(new Tea{});
			tea->prepare(200);
			return tea;
		}
	}

	std::unique_ptr<HotDrink> make_drink(std::string const& name)
	{
		return factories[name]();
	}

private:
	std::map<std::string, std::function<std::unique_ptr<HotDrink>()>> factories;
};
