#include <iostream>
#include <sstream>

class Expression
{
public:
    virtual ~Expression() = default;
};

class DoubleExpression : public Expression
{
public:
    DoubleExpression(double value) : _value{value}
    {}

    double getValue() const
    {
        return _value;
    }

private:
    double _value;
};

// 1 + 2 + 3
//     +
//    / \
//   1   +
//      / \
//     2   3
class AdditionExpression : public Expression
{
public:
    AdditionExpression(Expression* left, Expression* right)
        : _left{left}
        , _right{right}
    {}

    ~AdditionExpression()
    {
        delete _left;
        delete _right;
    }

    Expression* getLeft() const
    {
        return _left;
    }

    Expression* getRight() const
    {
        return _right;
    }

private:
    Expression* _left;
    Expression* _right;
};

class NonWorkingExpressionPrinter
{
public:
    void print(DoubleExpression* de, std::ostringstream& oss) const
    {
        oss << de->getValue();
    }

    void print(AdditionExpression* /*ae*/, std::ostringstream& oss) const
    {
        oss << "(";

        // here is the problem
        // the dispatch (which overload func. to call) happens at compile time
        // We do not have that information at compile time
        // print(ae->getLeft(), oss);
    }
};

class ExpressionPrinter
{
public:
    std::string str() const
    {
        return _oss.str();
    }

    // there are 3 main issues with this approach:
    // 1st - the dynamic cast is very costly
    // 2nd - we might forget about one Expression* type
    // 3rd - if new Expression* is created, we must keep editing this "if"
    void print(Expression* e)
    {
        if (auto de = dynamic_cast<DoubleExpression*>(e))
        {
            _oss << de->getValue();
        }
        else if (auto de = dynamic_cast<AdditionExpression*>(e))
        {
            _oss << "(";
            print(de->getLeft());
            _oss << "+";
            print(de->getRight());
            _oss << ")";
        }
    }

private:
    std::ostringstream _oss;
};

int main()
{
    auto e = new AdditionExpression (
                new DoubleExpression{1},
                new AdditionExpression (
                    new DoubleExpression{2},
                    new DoubleExpression{3}));

    // (1+(2+3))
    ExpressionPrinter ep;
    ep.print(e);
    std::cout << ep.str() << '\n';

    delete e;

    return 0;
}
