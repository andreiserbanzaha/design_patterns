#include <iostream>
#include <string>

class Creature
{
public:
	Creature(std::string const& name, int attack, int defense)
		: _name{name}
		, _attack{attack}
		, _defense{defense}
	{}

	friend std::ostream& operator<<(std::ostream& os, Creature const& creature)
	{
		os << creature._name << " " << creature._attack << " " << creature._defense;
		return os;
	}

	std::string _name;
	int _attack;
	int _defense;
};

class CreatureModifier
{
public:
	CreatureModifier(Creature& creature)
		: _creature{creature}
	{}

	void add(CreatureModifier* cm)
	{
		if (_next) { _next->add(cm); }
		else { _next = cm; }
	}

	virtual void handle()
	{
		if (_next) { _next->handle(); }
	}

protected:
	Creature& _creature;

private:
	CreatureModifier* _next{nullptr};
};

class DoubleAttackModifier : public CreatureModifier
{
public:
	DoubleAttackModifier(Creature& creature)
		: CreatureModifier{creature}
	{}

	void handle() override
	{
		_creature._attack *= 2;
		CreatureModifier::handle();
	}
};

class IncreaseDefenseModifier : public CreatureModifier
{
public:
	IncreaseDefenseModifier(Creature& creature)
		: CreatureModifier{creature}
	{}

	void handle() override
	{
		if (_creature._attack <= 2) { ++_creature._defense; }
		CreatureModifier::handle();
	}
};

class NoBonusesModifier : public CreatureModifier
{
public:
	NoBonusesModifier(Creature& creature)
		: CreatureModifier{creature}
	{}

	// prevent walking on the chain of responsibility
	void handle() override
	{
	}
};

int main()
{
	Creature goblin{"Goblin", 1, 1};
	CreatureModifier root{goblin};
	DoubleAttackModifier r1{goblin};
	DoubleAttackModifier r1_2{goblin};
	IncreaseDefenseModifier r2{goblin};
	NoBonusesModifier curse{goblin};

	root.add(&curse);
	root.add(&r1);
	root.add(&r1_2);
	root.add(&r2);

	root.handle();
	std::cout << goblin << '\n';

	return 0;
}
