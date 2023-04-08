#include <iostream>
#include <variant>
#include <string>
#include <type_traits>

class AddressPrinter
{
public:
    void operator()(std::string const& houseName) const
    {
        std::cout << "House is called " << houseName << '\n';
    }

    void operator()(int houseNumber) const
    {
        std::cout << "House is at number " << houseNumber << '\n';
    }
};

int main()
{
    std::variant<std::string, int> house;

    house = 123;
    AddressPrinter ap;
    std::visit(ap, house);

    house = "Montefiore Castle";
    std::visit([](auto& arg)
    {
        using T = std::decay_t<decltype (arg)>;
        if constexpr(std::is_same_v<T, std::string>)
        {
            std::cout << "House is called " << arg << '\n';
        }
        else
        {
            std::cout << "House is at number " << arg << '\n';
        }
    }, house);

    return 0;
}
