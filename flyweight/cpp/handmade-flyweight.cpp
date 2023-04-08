#include <iostream>
#include <string>
#include <boost/bimap.hpp>

typedef uint32_t key;

class User
{
public:
    User(std::string const& aFirstName, std::string const& aLastName)
        : firstName { addKey(aFirstName) }
        , lastName  { addKey(aLastName)  }
    {}

    std::string const& getFirstName() const
    {
        return names.left.find(firstName)->second;
    }

    std::string const& getLastName() const
    {
        return names.left.find(lastName)->second;
    }

    key firstName;
    key lastName;

protected:
    static boost::bimap<key, std::string> names;
    static key seed;

    static key addKey(std::string const& str)
    {
        auto it = names.right.find(str);
        if (it == names.right.end())
        {
            key id = ++seed;
            names.insert({seed, str});
            return id;
        }
        return it->second;
    }
};

key User::seed{0};
boost::bimap<key, std::string> User::names{};

std::ostream& operator<<(std::ostream& aOs, User const& aUser)
{
    aOs << "first name: " << aUser.getFirstName() <<
           ", last name: " << aUser.getLastName() <<
           "(" << aUser.lastName << ")";
    return aOs;
}

int main()
{
    User user1{"John", "Smith"};
    User user2{"Jane", "Smith"};

    std::cout << user1 << '\n' << user2 << '\n';

    return 0;
}

