#include <iostream>
#include <vector>

class BankAccount
{
public:
    BankAccount()
        : _balance{0}
        , _overdraftLimit{-500}
    {
    }

    void deposit(int amount)
    {
        _balance += amount;
        std::cout << "deposited " << amount <<
                     ", balance is now " << _balance << '\n';
    }

    bool withdraw(int amount)
    {
        if (_balance - amount >= _overdraftLimit)
        {
            _balance -= amount;
            std::cout << "withdrew " << amount <<
                         ", balance is now " << _balance << '\n';
            return true;
        }
        return false;
    }

    int getBalance() const
    {
        return _balance;
    }

    friend std::ostream& operator <<(std::ostream& os, const BankAccount& ba)
    {
        os << "balance: " << ba.getBalance();
        return os;
    }

private:
    int _balance;
    int _overdraftLimit;
};

class Command
{
public:
    bool succeeded;

    virtual void call() = 0;
    virtual void undo() = 0;
};

class BankAccountCommand : public Command
{
public:
    enum class Action
    {
        eDeposit,
        eWithdraw
    };

    BankAccountCommand(BankAccount& ba, BankAccountCommand::Action a, int amount)
        : _bankAccount{ba}
        , _action{a}
        , _amount{amount}
    {
        succeeded = false;
    }

    void call() override
    {
        switch(_action)
        {
        case BankAccountCommand::Action::eDeposit:
            _bankAccount.deposit(_amount);
            succeeded = true;
            break;
        case BankAccountCommand::Action::eWithdraw:
            succeeded = _bankAccount.withdraw(_amount);
            break;
        }
    }

    void undo() override
    {
        if (!succeeded)
        {
            return;
        }

        switch(_action)
        {
        case BankAccountCommand::Action::eDeposit:
            _bankAccount.withdraw(_amount);
            break;
        case BankAccountCommand::Action::eWithdraw:
            _bankAccount.deposit(_amount);
            break;
        }
    }

private:
    BankAccount& _bankAccount;
    Action _action;
    int _amount;
};

class CompositeBankAccountCommand:
        public std::vector<BankAccountCommand>,
        public Command
{
public:
    CompositeBankAccountCommand(
            const std::initializer_list<BankAccountCommand>& items)
        : std::vector<BankAccountCommand>(items)
    {
    }

    void call() override
    {
        for(auto& cmd : *this)
        {
            cmd.call();
        }
    }

    void undo() override
    {
        for(auto it = rbegin(); it != rend(); ++it)
        {
            it->undo();
        }
    };
};

class DependentCompositeCommand : public CompositeBankAccountCommand
{
public:
    DependentCompositeCommand(const std::initializer_list<BankAccountCommand>& items)
        : CompositeBankAccountCommand{items}
    {}

    void call() override
    {
        bool ok = true;
        for (auto& cmd : *this)
        {
            if (ok)
            {
                cmd.call();
                ok = cmd.succeeded;
            }
            else
            {
                cmd.succeeded = false;
            }
        }
    }
};

//class MoneyTransferCommand : public CompositeBankAccountCommand
//{
//public:
//    MoneyTransferCommand(BankAccount& from, BankAccount& to, int amount)
//        : CompositeBankAccountCommand(
//    {
//              BankAccountCommand{from, BankAccountCommand::Action::eWithdraw, amount},
//              BankAccountCommand{to, BankAccountCommand::Action::eDeposit, amount}
//    })
//    {}
//};

class MoneyTransferCommand : public DependentCompositeCommand
{
public:
    MoneyTransferCommand(BankAccount& from, BankAccount& to, int amount)
        : DependentCompositeCommand(
    {
              BankAccountCommand{from, BankAccountCommand::Action::eWithdraw, amount},
              BankAccountCommand{to, BankAccountCommand::Action::eDeposit, amount}
})
    {}
};

int main()
{
    BankAccount ba;
    BankAccount ba2;

    ba.deposit(100);
    MoneyTransferCommand cmd {ba, ba2, 600000};
    cmd.call();
    std::cout << ba <<'\n' << ba2 << "\n\n";
    cmd.undo();
    std::cout << ba <<'\n' << ba2 << '\n';

    return 0;
}
