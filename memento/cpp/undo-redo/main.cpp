#include <iostream>
#include <string>
#include <memory>
#include <vector>

// this object should not be able to be modified
class Memento
{
    // can be done in other ways (e.g class inside BankAccount)
    friend class BankAccount;

public:
    Memento(int balance)
        : _balance{balance}
    {}

private:
    int _balance;
};

class BankAccount
{
public:
    BankAccount(int balance)
        : _balance{balance}
    {
        _changes.emplace_back(std::make_shared<Memento>(_balance));
        _current = 0;
    }

    std::shared_ptr<Memento> deposit(int amount)
    {
        _balance += amount;
        auto m = std::make_shared<Memento>(_balance);
        _changes.emplace_back(m);
        ++_current;
        return m;
    }

    void restore(std::shared_ptr<Memento> const& m)
    {
        if (m)
        {
            _balance = m->_balance;
            _changes.emplace_back(m);
            _current = _changes.size() - 1;
        }
    }

    std::shared_ptr<Memento> undo()
    {
        if (_current > 0)
        {
            --_current;
            auto m = _changes[_current];
            _balance = m->_balance;
            return m;
        }
        return {};
    }

    std::shared_ptr<Memento> redo()
    {
        if (_current + 1 < _changes.size())
        {
            ++_current;
            auto m = _changes[_current];
            _balance = m->_balance;
            return m;
        }
        return {};
    }

    friend std::ostream& operator<<(std::ostream& os,
                                    BankAccount const& ba)
    {
        os << "balance: " << ba._balance;
        return os;
    }

private:
    int _balance{0};
    std::vector<std::shared_ptr<Memento>> _changes;
    int _current; // index of changes
};

int main()
{
    BankAccount ba{100};
    ba.deposit(50);
    ba.deposit(25);

    std::cout << ba << '\n';

    ba.undo();
    std::cout << "undo 1: " << ba << '\n';

    ba.undo();
    std::cout << "undo 2: " << ba << '\n';

    ba.redo();
    std::cout << "redo: " << ba << '\n';
    return 0;
}
