#include <iostream>
#include <typeindex>
#include <map>

class GameObject;
void collide (GameObject& first, GameObject& second);

class GameObject
{
public:
    virtual std::type_index type() const = 0;
    virtual void collide(GameObject& other)
    {
        ::collide(*this, other);
    }
};

// CRTP
template <typename T>
class GameObjectImpl : public GameObject
{
public:
    std::type_index type() const override
    {
        return typeid(T);
    }
};

class Planet    : public GameObjectImpl<Planet> {};
class Spaceship : public GameObjectImpl<Spaceship> {};
class Asteroid  : public GameObjectImpl<Asteroid> {};

void spaceshipAndPlanetCollision()
{
    std::cout << "Spaceship lands on planet.\n";
};

void asteroidAndPlanetCollision()
{
    std::cout << "Asteroid burns in the atmosphere.\n";
};

void spaceshipAndAsteroidCollision()
{
    std::cout << "Spaceship is destroyed by asteroid.\n";
};

std::map<std::pair<std::type_index, std::type_index>, void(*)(void)> outcomes {
    {{typeid (Spaceship), typeid (Planet)}, spaceshipAndPlanetCollision},
    {{typeid (Spaceship), typeid (Asteroid)}, spaceshipAndAsteroidCollision},
    {{typeid (Asteroid), typeid (Planet)}, asteroidAndPlanetCollision}
};

void collide (GameObject& first, GameObject& second)
{
    auto it = outcomes.find({first.type(), second.type()});

    if (it == outcomes.end())
    {
        it = outcomes.find({second.type(), first.type()});
        if (it == outcomes.end())
        {
            std::cout << "Objects have passed each other.\n";
            return;
        }
    }
    it->second();
}

int main()
{
    Asteroid a;
    Planet p;
    Spaceship s;

    collide(p, s);
    collide(a, s);
    collide(a, p);
    collide(p, p);

    return 0;
}
