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

int main()
{
    BankAccount ba;
    std::vector<BankAccountCommand> commands
    {
        BankAccountCommand{ba, BankAccountCommand::Action::eDeposit, 100},
        BankAccountCommand{ba, BankAccountCommand::Action::eWithdraw, 200}
    };

    std::cout << ba << '\n';
    for(auto& cmd : commands)
    {
        cmd.call();
    }
    for (auto it= commands.rbegin(); it != commands.rend(); ++it)
    {
        it->undo();
    }
    std::cout << ba << '\n';

    return 0;
}
