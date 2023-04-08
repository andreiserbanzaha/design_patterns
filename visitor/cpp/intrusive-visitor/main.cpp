#include <iostream>
#include <sstream>

class Expression
{
public:
    ~Expression() = default;

    // This is basically the visitor
    // intrusive because we must modify the classes if we want to change
    virtual void print(std::ostringstream& oss) = 0;
};

class DoubleExpression : public Expression
{
public:
    DoubleExpression(double value) : _value{value}
    {
    }

    void print(std::ostringstream& oss) override
    {
        oss << _value;
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

    void print(std::ostringstream& oss) override
    {
        oss << "(";
        _left->print(oss);
        oss << "+";
        _right->print(oss);
        oss << ")";
    }

private:
    Expression* _left;
    Expression* _right;
};

int main()
{
    auto e = new AdditionExpression (
                new DoubleExpression{1},
                new AdditionExpression (
                    new DoubleExpression{2},
                    new DoubleExpression{3}));

    // (1+(2+3))
    std::ostringstream oss;
    e->print(oss);
    std::cout << oss.str() << '\n';

    delete e;

    return 0;
}
