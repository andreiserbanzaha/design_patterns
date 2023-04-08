#include <iostream>
#include <string>
#include <vector>

enum class eColor { red = 0, green, blue };
enum class eSize { small = 0, medium, large };

struct Product
{
	std::string name;
	eColor color;
	eSize size;
};

template <typename T>
struct AndSpecification;

template <typename T>
struct Specification
{
	virtual bool isSatisfied(T* item) = 0;

	// optional
	AndSpecification<T> operator&&(Specification<T>&& otherSpecification)
	{
		return AndSpecification<T>(*this, otherSpecification);
	}
};

template <typename T>
struct Filter
{
	virtual std::vector<T*> filter(std::vector<T*> items,
                                   Specification<T>& specification) = 0;
};

struct ProductFilter : public Filter<Product>
{
	std::vector<Product*> filter(std::vector<Product*> items,
                                 Specification<Product>& specification) override
	{
		std::vector<Product*> result;
		for (auto& item : items)
		{
			if (specification.isSatisfied(item))
			{
				result.push_back(item);
			}
		}
		return result;
	}
};

struct ColorSpecification : public Specification<Product>
{
	eColor color;

	ColorSpecification(eColor aColor) 
		: color {aColor}
	{}

	bool isSatisfied(Product* item) override
	{
		return item->color == color;
	}
};

struct SizeSpecification : public Specification<Product>
{
	eSize size;

	SizeSpecification(eSize aSize) 
		: size {aSize}
	{}

	bool isSatisfied(Product* item) override
	{
		return item->size == size;
	}
};

template <typename T>
struct AndSpecification : public Specification<T>
{
	Specification<T>& first;
	Specification<T>& second;

	AndSpecification(Specification<T>& aFirst,
                     Specification<T>& aSecond)
		: first{aFirst}
		, second{aSecond}
	{}

	bool isSatisfied(T* item) override
	{
		return first.isSatisfied(item) && second.isSatisfied(item);
	}
};

int main()
{
	Product apple{"Apple", eColor::green, eSize::small};
	Product tree {"Tree", eColor::green, eSize::large};
	Product house{"House", eColor::blue, eSize::large};
	std::vector<Product*> products {&apple, &tree, &house};

	ProductFilter pf;
	ColorSpecification greenSpecification(eColor::green);
	SizeSpecification  largeSpecification(eSize::large);

	for (auto& p : pf.filter(products, greenSpecification))
		std::cout << p->name << " is green\n";
	for (auto& p : pf.filter(products, largeSpecification))
		std::cout << p->name << " is large\n";

	AndSpecification<Product> greenAndLarge(greenSpecification,
			                                largeSpecification);
	for (auto& p : pf.filter(products, greenAndLarge))
		std::cout << p->name << " is green and large\n";

	auto blueAndLargeSpecification = ColorSpecification(eColor::blue) &&
		SizeSpecification(eSize::large);
	for (auto& p : pf.filter(products, blueAndLargeSpecification))
		std::cout << p->name << " is blue and large\n";

	return 0;
}
