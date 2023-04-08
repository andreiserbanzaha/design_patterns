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

int main()
{
    Person p{10};
    ConsolePersonObserver cpo;

    p.subscribe(cpo);
    p.setAge(12);
    p.setAge(13);

    p.unsubscribe(cpo);
    p.setAge(14);
    p.setAge(15);

    p.subscribe(cpo);
    p.setAge(18);
    p.setAge(7);

    return 0;
}
