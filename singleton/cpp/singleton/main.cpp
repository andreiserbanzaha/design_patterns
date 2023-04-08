#include <iostream>
#include <fstream>
#include <map>
#include <boost/lexical_cast.hpp>

class SingletonDatabase
{
public:
	SingletonDatabase(SingletonDatabase const&) = delete;
	void operator=(SingletonDatabase const&) = delete;

	static SingletonDatabase& get()
	{
		static SingletonDatabase db;
		return db;
	}

	int getPopulation(std::string const& name)
	{
		return m_capitals[name];
	}

private:
	SingletonDatabase()
	{
		std::cout << "Initializing database!\n";
		std::ifstream ifs("capitals.txt");

		std::string capital;
		std::string population;

		while (getline(ifs, capital))
		{
			getline(ifs, population);
			int pop = boost::lexical_cast<int>(population);
			m_capitals[capital] = pop;
		}
	}

private:
	std::map<std::string, int> m_capitals;
};

int main()
{
	std::cout << SingletonDatabase::get().getPopulation("bucharest") << '\n';

	return 0;
}
