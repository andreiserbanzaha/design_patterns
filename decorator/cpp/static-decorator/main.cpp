#include <iostream>
#include <utility>
#include <sstream>
#include <string>

class Shape
{
public:
    virtual std::string str() const = 0;
};

class Circle : public Shape
{
public:
    Circle(float radius) : _radius{radius} {}

    void resize(float factor) { _radius *= factor; }

    std::string str() const override
    {
        std::ostringstream oss;
        oss << "a circle of radius: " << _radius;
        return oss.str();
    }

private:
    float _radius;
};

class Square : public Shape
{
public:
    Square(float side) : _side{side} {}

    std::string str() const override
    {
        std::ostringstream oss;
        oss << "a square with side of: " << _side;
        return oss.str();
    }

private:
    float _side;
};

template <typename T>
class ColoredShape : public T
{
    static_assert(std::is_base_of<Shape, T>::value,
    "Template argument must be a Shape");
public:
    template <typename ...Args>
    ColoredShape(std::string const& color, Args ...args)
        : T(std::forward<Args>(args)...)
        ,_color{color}
    {}

    std::string str() const override
    {
        std::ostringstream oss;
        oss << T::str() << " and has color: " << _color;
        return oss.str();
    }

private:
    std::string _color;
};

template <typename T>
class TransparentShape : public T
{
    static_assert(std::is_base_of<Shape, T>::value,
    "Template argument must be a Shape");

public:
    template <typename ...Args>
    TransparentShape(uint8_t transparency, Args ...args)
        : T(std::forward<Args>(args)...)
        , _transparency{transparency}
    {}

    std::string str() const override
    {
        std::ostringstream oss;
        oss << T::str()
            << " has "
            << static_cast<float>(_transparency) / 255.f * 100.f
            << "% transparency.";
        return oss.str();
    }

private:
    uint8_t _transparency;
};

int main()
{
    ColoredShape<Circle> greenCircle {"green", 5};
    std::cout << greenCircle.str() << '\n';
    greenCircle.resize(2);
    std::cout << greenCircle.str() << '\n';

    TransparentShape<ColoredShape<Square>> sq{51, "blue", 10};
    std::cout << sq.str() << '\n';

    return 0;
}
