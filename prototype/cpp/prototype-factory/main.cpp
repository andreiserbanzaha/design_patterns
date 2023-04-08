#include <iostream>
#include <string>
#include <memory>

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

class EmployeeFactory
{
public:
    static std::unique_ptr<Contact> newMainOfficeEmployee(
            std::string const& aName,
            int aNumber)
    {
        static Contact p {"", new Address{"123 East Dr", "London", 0}};
        return newEmployee(aName, aNumber, p);
    }

private:
    static std::unique_ptr<Contact> newEmployee(std::string const& aName,
                                                int aNumber,
                                                Contact const& aPrototype)
    {
        std::unique_ptr<Contact> res{new Contact{aPrototype}};
        res->name = aName;
        res->address->number = aNumber;
        return res;
    }
};

int main()
{
    auto john = EmployeeFactory::newMainOfficeEmployee("John", 123);
    john->print();

    return 0;
}
