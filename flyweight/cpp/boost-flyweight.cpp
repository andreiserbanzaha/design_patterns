#include <iostream>
#include <string>
#include <boost/flyweight.hpp>

typedef uint32_t key;

class User
{
public:
    User(std::string const& aFirstName, std::string const& aLastName)
        : firstName{aFirstName}
        , lastName{aLastName}
    {}
	
	boost::flyweight<std::string> firstName;
	boost::flyweight<std::string> lastName;
};

int main()
{
    User user1{"John", "Smith"};
    User user2{"Jane", "Smith"};

    std::cout << std::boolalpha << "same firstName: " <<
		(&user1.firstName.get() == &user2.firstName.get()) << '\n';

    std::cout << std::boolalpha << "same lastName: " <<
		(&user1.lastName.get() == &user2.lastName.get()) << '\n';

    return 0;
}

