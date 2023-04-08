#include <iostream>
#include <sstream>

class DoubleExpression;
class AdditionExpression;
class SubtractionExpression;

class ExpressionVisitor
{
public:
    virtual void visit(DoubleExpression* de) = 0;
    virtual void visit(AdditionExpression* ae) = 0;
    virtual void visit(SubtractionExpression* se) = 0;
};

class ExpressionPrinter : public ExpressionVisitor
{
public:
    void visit(DoubleExpression* de) override;
    void visit(AdditionExpression* ae) override;
    void visit(SubtractionExpression* se) override;

    std::string str() const
    {
        return _oss.str();
    }

private:
    std::ostringstream _oss;
};

class ExpressionEvaluator : public ExpressionVisitor
{
public:
    void visit(DoubleExpression* de) override;
    void visit(AdditionExpression* ae) override;
    void visit(SubtractionExpression* se) override;

    double getResult() const
    {
        return _result;
    }

private:
    double _result;
};

class Expression
{
public:
    virtual void accept(ExpressionVisitor* visitor) = 0;

    virtual ~Expression() = default;
};

class DoubleExpression : public Expression
{
public:
    DoubleExpression(double value) : _value{value}
    {}

    void accept(ExpressionVisitor* visitor)
    {
        visitor->visit(this);
    }

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

    void accept(ExpressionVisitor* visitor)
    {
        visitor->visit(this);
    }

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

class SubtractionExpression : public Expression
{
public:
    SubtractionExpression(Expression* left, Expression* right)
        : _left{left}
        , _right{right}
    {}

    void accept(ExpressionVisitor* visitor)
    {
        visitor->visit(this);
    }

    ~SubtractionExpression()
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

void ExpressionPrinter::visit(DoubleExpression *de)
{
    _oss << de->getValue();
}

void ExpressionPrinter::visit(AdditionExpression* ae)
{
    bool needBraces = dynamic_cast<SubtractionExpression*>(ae->getRight());
    ae->getLeft()->accept(this);
    _oss << "+";
    if (needBraces) { _oss << "("; }
    ae->getRight()->accept(this);
    if (needBraces) { _oss << ")"; }
}

void ExpressionPrinter::visit(SubtractionExpression *se)
{
    bool needBraces = dynamic_cast<SubtractionExpression*>(se->getRight());
    if (needBraces) { _oss << "("; }
    se->getLeft()->accept(this);
    _oss << "-";
    se->getRight()->accept(this);
    if (needBraces) { _oss << ")"; }
}

void ExpressionEvaluator::visit(DoubleExpression *de)
{
    _result = de->getValue();
}

void ExpressionEvaluator::visit(AdditionExpression* ae)
{
    ae->getLeft()->accept(this);
    auto temp = _result;
    ae->getRight()->accept(this);
    _result += temp;
}

void ExpressionEvaluator::visit(SubtractionExpression *se)
{
    se->getLeft()->accept(this);
    auto temp = _result;
    se->getRight()->accept(this);
    _result -= temp;
}

int main()
{
    auto e = new AdditionExpression (
                new DoubleExpression(1),
                new SubtractionExpression (
                    new DoubleExpression(2),
                    new DoubleExpression(1)
                    )
                ); // 1+(2-1)

    ExpressionPrinter ep;
    ep.visit(e);
    std::cout << ep.str() << '\n';

    ExpressionEvaluator eval;
    eval.visit(e);
    std::cout << ep.str() << " = " << eval.getResult() << '\n';

    return 0;
}
