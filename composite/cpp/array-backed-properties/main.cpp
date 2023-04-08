#include <iostream>
#include <algorithm>
#include <array>
#include <numeric>

//class Creature
//{
//public:
//	int getStrength() const { return _strength; }
//	int getIntelligence() const { return _intelligence; }
//	int getAgility() const { return _agility; }

//	void setStrength(int aStrength) { _strength = aStrength; }
//	void setIntelligence(int aIntelligence) { _intelligence = aIntelligence; }
//	void setAgility(int aAgility) { _agility = aAgility; }

//	int sum() const { return _strength + _intelligence + _agility; }
//	double average() const { return sum() / 3.0; }
//  int max() const
//  {
//      return std::max(std::max(_strength, _agility), _intelligence);
//  }

//private:
//	int _strength, _intelligence, _agility;
//};

// better implementation
class Creature
{
public:
    int getStrength() const { return _abilities[EAbilities::strength]; }
    int getIntelligence() const { return _abilities[EAbilities::intelligence]; }
    int getAgility() const { return _abilities[EAbilities::agility]; }

    void setStr(int str) { _abilities[EAbilities::strength] = str; }
    void setIntl(int intl) { _abilities[EAbilities::intelligence] = intl; }
    void setAgl(int agl) { _abilities[EAbilities::agility] = agl; }

    int sum() const
    {
        return std::accumulate(_abilities.begin(), _abilities.end(), 0);
    }

    double average() const
    {
        return sum() / static_cast<double>(EAbilities::count);
    }

    int max() const
    {
        return *std::max_element(_abilities.begin(), _abilities.end());
    }

private:
    enum EAbilities
    {
        strength = 0,
        intelligence,
        agility,
        count // value of this is the number of elements in the enum
    };
    std::array<int, EAbilities::count> _abilities;
};

int main()
{
    Creature c;
    c.setStr(15);
    c.setAgl(20);
    c.setIntl(23);

    std::cout << "C has and sum of: " << c.sum() << '\n';
    std::cout << "C has and average of: " << c.average() << '\n';
    std::cout << "C has and max of: " << c.max() << '\n';

    return 0;
}
