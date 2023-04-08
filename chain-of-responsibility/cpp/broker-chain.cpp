#include <iostream>
#include <string>
#include <boost/signals2.hpp>

// event broker = chain of responsibility + 
//					observer pattern + 
//					command query separation

struct Query
{

	std::string creatureName;
	enum Argument{ attack, defense } argument;
	int result;

	Query(std::string const& aCreatureName, Argument aArgument, int aResult)
		: creatureName{aCreatureName}
		, argument{aArgument}
		, result{aResult}
	{}
};

struct Game // mediator design pattern
{
	boost::signals2::signal<void(Query&)> queries;
};

struct Creature
{
	Creature(Game& aGame, std::string const& aName, int aAttack, int aDefense)
		: game{aGame}
		, name{aName}
		, attack{aAttack}
		, defense{aDefense}
	{}

	int getAttack() const
	{
		Query q{name, Query::Argument::attack, attack};
		game.queries(q);
		return q.result;
	}

	friend std::ostream& operator<<(std::ostream& os, Creature const& creature)
	{
		os << creature.getAttack() << " " << creature.name;
		return os;
	}
	
	Game& game;
	int attack;
	int defense;
	std::string name;
};

class CreatureModifier
{
public:
	CreatureModifier(Game& aGame, Creature& aCreature)
		: game{aGame}
		, creature{aCreature}
	{}

	virtual ~CreatureModifier() = default;

private:
	Game& game;
	Creature& creature;
};

class DoubleAttackModifier : public CreatureModifier
{
	boost::signals2::connection conn;
public:
	DoubleAttackModifier(Game& aGame, Creature& aCreature)
		: CreatureModifier{aGame, aCreature}
	{
		conn = aGame.queries.connect([&](Query& q)
				{
					if (q.creatureName == aCreature.name &&
							q.argument == Query::Argument::attack)
					{
						q.result *= 2;
					}
				});
	}

	~DoubleAttackModifier()
	{
		conn.disconnect();
	}
};

int main()
{
	Game game;
	Creature goblin{game, "Strong Goblin", 2, 2};

	std::cout << goblin << '\n';

	{
		DoubleAttackModifier dam{game, goblin};
		std::cout << goblin << '\n';
	}

	std::cout << goblin << '\n';

	return 0;
}
