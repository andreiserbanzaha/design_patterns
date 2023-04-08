#include <map>
#include <memory>
#include <iostream>

enum class EImportance
{
	primary = 0,
	secondary,
	tertiary
};

template <typename T, typename Key = std::string>
class Multiton
{
public:
	static std::shared_ptr<T> get(Key const& aKey)
	{
		auto it = instances.find(aKey);
		if (it != instances.end())
		{
			return it->second;
		}

		auto instance = std::make_shared<T>();
		instances[aKey] = instance;
		return instance;
	}

protected:
	Multiton() = default;
	virtual ~Multiton() = default;

private:
	static std::map<Key, std::shared_ptr<T>> instances;
};

template <typename T, typename Key>
std::map<Key, std::shared_ptr<T>> Multiton<T, Key>::instances;

class Printer
{
public:
	Printer()
	{
		++Printer::totalInstanceCount;
		std::cout << Printer::totalInstanceCount << " instances created!\n";
	}

private:
	static int totalInstanceCount;
};

int Printer::totalInstanceCount = 0;

int main()
{
	typedef Multiton<Printer, EImportance> mt;

	auto main = mt::get(EImportance::primary);
	auto aux = mt::get(EImportance::secondary);
	auto aux2 = mt::get(EImportance::secondary);

	return 0;
}
