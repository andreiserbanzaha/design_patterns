#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

class Token
{
public:
    enum class EType
    {
        Integer,
        Plus,
        Minus,
        LeftParenthesis,
        RightParenthesis
    };

    Token(std::string const& text, Token::EType type)
        : _text{text}
        , _type{type}
    {}

    std::string getText() const
    {
        return _text;
    }

    EType getType() const
    {
        return _type;
    }

    friend std::ostream& operator<<(std::ostream& os, Token const& token)
    {
        os << '`' << token.getText() << '`';
        return os;
    }

private:
    std::string _text;
    EType _type;
};

std::vector<Token> lex(std::string const& input)
{
    std::vector<Token> res;

    for (unsigned long i = 0; i < input.size(); ++i)
    {
        switch(input[i])
        {
        case '+':
            res.push_back(Token{"+", Token::EType::Plus});
            break;
        case '-':
            res.push_back(Token{"-", Token::EType::Minus});
            break;
        case '(':
            res.push_back(Token{"(", Token::EType::LeftParenthesis});
            break;
        case ')':
            res.push_back(Token{")", Token::EType::RightParenthesis});
            break;
        default:
            std::ostringstream buffer;
            buffer << input[i];
            for (unsigned long j = i + 1; j < input.size(); ++j)
            {
                if (isdigit(input[j]))
                {
                    buffer << input[j];
                    ++i;
                }
                else
                {
                    res.push_back(Token{buffer.str(), Token::EType::Integer});
                    break;
                }
            }
        }
    }

    return res;
}

class Element
{
public:
    virtual int eval() const = 0;
};

class Integer : public Element
{
public:
    Integer(int value)
        : _value{value}
    {}

    int eval() const override
    {
        return _value;
    }

private:
    int _value;
};

class BinaryOperation : public Element
{
public:
    enum class EType
    {
        Addition,
        Subtraction
    };

    BinaryOperation()
    {
    }

    int eval() const override
    {
        auto left = _lhs->eval();
        auto right = _rhs->eval();

        if (_type == EType::Addition)
        {
            return left + right;
        }
        return left - right;
    }

    void setType(EType type)
    {
        _type = type;
    }

    void setRhs(std::shared_ptr<Element> rhs)
    {
        _rhs = rhs;
    }

    void setLhs(std::shared_ptr<Element> lhs)
    {
        _lhs = lhs;
    }

private:
    EType _type;
    std::shared_ptr<Element> _rhs, _lhs;
};

std::shared_ptr<Element> parse(std::vector<Token> const& tokens)
{
    auto res = std::make_unique<BinaryOperation>();
    bool haveLhs{false};

    for (unsigned long i = 0; i < tokens.size(); ++i)
    {
        auto& token = tokens[i];

        switch (token.getType())
        {
        case Token::EType::Integer:
        {
            int val = std::stoi(token.getText().c_str());
            auto integer = std::make_shared<Integer>(val);
            if (!haveLhs)
            {
                res->setLhs(integer);
                haveLhs = true;
            }
            else
            {
                res->setRhs(integer);
            }
            break;
        }
        case Token::EType::Minus:
        {
            res->setType(BinaryOperation::EType::Subtraction);
            break;
        }
        case Token::EType::Plus:
        {
            res->setType(BinaryOperation::EType::Addition);
            break;
        }
        case Token::EType::LeftParenthesis:
        {
            unsigned long j = i;
            for (; j < tokens.size(); ++j)
            {
                if (tokens[j].getType() == Token::EType::RightParenthesis)
                {
                    break;
                }
            }

            std::vector<Token> subexpression{&tokens[i+1], &tokens[j]};
            auto el = parse(subexpression);
            if (!haveLhs)
            {
                res->setLhs(el);
                haveLhs = true;
            }
            else
            {
                res->setRhs(el);
            }
            i = j;
            break;
        }
        }
    }
    return res;
}

int main()
{
    std::string input{"(13-4)-(12+1)"};

    auto tokens = lex(input);

    for (auto& t : tokens)
    {
        std::cout << t << ' ';
    }
    std::cout << '\n';

    try
    {
        auto parsed = parse(tokens);
        std::cout << input << " = " << parsed->eval() << '\n';
    }
    catch (std::exception const& e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}
