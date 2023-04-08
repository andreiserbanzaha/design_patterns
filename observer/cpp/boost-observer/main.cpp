#include <iostream>
#include <boost/signals2/signal.hpp>

template<typename T>
class Observable
{
public:
    boost::signals2::signal<void(T&, std::string const&)> fieldChanged;
};

class Person : public Observable<Person>
{
public:
    int getAge() const { return _age; }

    void setAge(int age)
    {
        if (_age == age) { return; }

        _age = age;
        fieldChanged(*this, "age");
    }

private:
    int _age;
};

int main()
{
    Person p;
    auto conn = p.fieldChanged.connect(
                [](Person& p, std::string const& fieldName){
            std::cout << fieldName << " has changed to " << p.getAge() << "!\n";
    });
    p.setAge(20);
    conn.disconnect();
    p.setAge(30);
    return 0;
}
