#include <iostream>

// this object should not be able to be modified
class Memento
{
    // can be done in other ways (e.g class inside BankAccount)
    friend class BankAccount;

public:
    Memento(int balance) : _balance{balance}
    {}

private:
    int _balance;
};

class BankAccount
{
public:
    BankAccount(int balance) : _balance{balance}
    {}

    Memento deposit(int amount)
    {
        _balance += amount;
        return {_balance};
    }

    void restore(Memento const& m)
    {
        _balance = m._balance;
    }

    void printBalance()
    {
        std::cout << "balance: " << _balance << '\n';
    }

private:
    int _balance{0};
};

int main()
{
    BankAccount ba{100};
    auto m1 = ba.deposit(50);
    auto m2 = ba.deposit(25);

    ba.printBalance();

    ba.restore(m1);
    ba.printBalance();

    ba.restore(m2);
    ba.printBalance();

    return 0;
}
