#include "observer.h"
#include "observable.h"
#include <iostream>

class Person : public Observable<Person>
{
public:
    Person(int age) : _age{age}
    {}

    int getAge() const
    {
        return _age;
    }

    void setAge(int age)
    {
        if (age == _age) { return; }

        bool couldVoteBefore = canVote();
        _age = age;
        notify(*this, "age");
        if (couldVoteBefore != canVote())
        {
            notify(*this, "canVote");
        }
    }

    bool canVote()
    {
        return _age >= 18;
    }

private:
    int _age;
};

class ConsolePersonObserver : public Observer<Person>
{
public:
    void fieldChanged(Person& source, std::string const& fieldName) override
    {
        std::cout << "Person's " << fieldName << " has changed to ";

        if (fieldName == "age")
        {
            std::cout << source.getAge() << '\n';
        }
        else if (fieldName == "canVote")
        {
            std::cout << std::boolalpha << source.canVote() << '\n';
        }
    }
};

class TrafficAdministration : public Observer<Person>
{
public:
    void fieldChanged(Person& source, std::string const& fieldName)
    {
        if (fieldName == "age")
        {
            if (source.getAge() < 18)
            {
                std::cout << "Not old enough to drive!\n";
            }
            else
            {
                std::cout << "Old enough. No longer need to monitor!\n";
                source.unsubscribe(*this); // this should cause a deadlock
            }
        }
    }
};

int main()
{
    Person p{10};
    TrafficAdministration ta;
    p.subscribe(ta);

    p.setAge(17);

    try
    {
        p.setAge(18);
    }
    catch(std::exception const& e)
    {
        std::cout << "oops: " << e.what() << '\n';
    }

    return 0;
}
