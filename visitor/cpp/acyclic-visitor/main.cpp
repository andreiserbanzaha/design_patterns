#include <iostream>
#include <sstream>
#include <string>

template <typename Visitable>
class Visitor
{
public:
    virtual void visit(Visitable& obj) = 0;
};

class VisitorBase
{
public:
    virtual ~VisitorBase() = default;
};

class Expression
{
public:
    virtual ~Expression() = default;

    virtual void accept(VisitorBase& obj)
    {
        if (auto ev = dynamic_cast<Visitor<Expression>*>(&obj))
        {
            ev->visit(*this);
        }
    }
};

class DoubleExpression : public Expression
{
public:
    DoubleExpression(double value) : _value {value}
    {}

    void accept(VisitorBase& obj) override
    {
        if (auto ev = dynamic_cast<Visitor<DoubleExpression>*>(&obj))
        {
            ev->visit(*this);
        }
    }

    double getValue() const
    {
        return _value;
    }

private:
    double _value;
};

class AdditionExpression : public Expression
{
public:
    AdditionExpression(Expression* left, Expression* right)
        : _left{left}
        , _right{right}
    {

    }

    ~AdditionExpression()
    {
        delete _left;
        delete _right;
    }

    void accept(VisitorBase& obj) override
    {
        if (auto ev = dynamic_cast<Visitor<AdditionExpression>*>(&obj))
        {
            ev->visit(*this);
        }
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

class ExpressionPrinter :
        public VisitorBase,
        //        public Visitor<DoubleExpression>,
        public Visitor<AdditionExpression>
{
public:
    void visit(AdditionExpression& obj) override
    {
        _oss << "(";
        obj.getLeft()->accept(*this);
        _oss << "+";
        obj.getRight()->accept(*this);
        _oss << ")";
    }

    //    void visit(DoubleExpression& obj) override
    //    {
    //        _oss << obj.getValue();
    //    }

    std::string str() const
    {
        return _oss.str();
    }

private:
    std::ostringstream _oss;
};

int main()
{
    auto e = new AdditionExpression(
                new DoubleExpression(1),
                new AdditionExpression(
                    new DoubleExpression(2),
                    new DoubleExpression(3)
                    )
                );

    ExpressionPrinter ep;
    ep.visit(*e);
    std::cout << ep.str() << '\n';

    return 0;
}
