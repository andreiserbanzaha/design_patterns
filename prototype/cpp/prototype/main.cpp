#include <iostream>
#include <string>

class Address
{
public:
    Address(std::string const& aCity, std::string const& aStreet, int aNumber)
        : city{aCity}
        , street{aStreet}
        , number{aNumber}
    {}

    Address(Address const& other)
        : city{other.city}
        , street{other.street}
        , number{other.number}
    {}

    std::string city;
    std::string street;
    int number;
};

class Contact
{
public:
    Contact(std::string const& aName, Address* aAddress)
        : name{aName}
        , address{aAddress}
    {}

    Contact(Contact const& other)
        : name{other.name}
        , address{new Address{*other.address}}
    {}

    ~Contact()
    {
        delete address;
    }

    void print()
    {
        std::cout << name << " | " <<
                     address->city << ", " <<
                     address->street << ", " <<
                     address->number << '\n';
    }

    std::string name;
    Address* address;
};

int main()
{
    Contact john{"John Doe", new Address{"oradea", "cantemir", 12}};

    Contact mary{john};
    mary.name = "mary";
    mary.address->number = 23;

    john.print();
    mary.print();

    return 0;
}
