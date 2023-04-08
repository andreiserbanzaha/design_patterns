#include <iostream>
#include <string>
#include <boost/signals2.hpp>

struct EventData
{
    virtual void print() const = 0;
};

struct PlayerScoredData : public EventData
{
    PlayerScoredData(std::string const& aName,
                     int aGoalsScored)
        : name{aName}
        , goalsScoredSoFar{aGoalsScored}
    {}

    void print() const override
    {
        std::cout << name << "has scored! (they have "
                  << goalsScoredSoFar << " goals so far)\n";
    }

    std::string name;
    int goalsScoredSoFar;
};

struct Game
{
    boost::signals2::signal<void(EventData*)> events;
};

struct Player
{
    Player(std::string const& aName, Game& aGame)
        : name{aName}
        , game{aGame}
    {}

    void score()
    {
        ++goalsScored;
        PlayerScoredData ps{name, goalsScored};
        game.events(&ps);
    }

    std::string name;
    int goalsScored{0};
    Game& game;
};

struct Coach
{
    Coach(Game& aGame)
        : game{aGame}
    {
        game.events.connect([](EventData* e)
        {
            PlayerScoredData* ps = dynamic_cast<PlayerScoredData*>(e);
            if (ps && ps->goalsScoredSoFar > 2)
            {
                std::cout << "coach says well done, " << ps->name << "!\n";
            }
        });
    }

    Game& game;
};

int main()
{
    Game game;
    Player p{"sam", game};
    Coach c{game};

    p.score();
    p.score();
    p.score();

    return 0;
}
