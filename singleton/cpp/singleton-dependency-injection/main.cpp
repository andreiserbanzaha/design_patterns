#include <iostream>
#include <fstream>
#include <map>
#include <boost/lexical_cast.hpp>
#include <gtest/gtest.h>

class Database 
{
public:
	virtual int getPopulation(std::string const& capital) = 0;
};

class SingletonDatabase : public Database
{
public:
	SingletonDatabase(SingletonDatabase const&) = delete;
	void operator=(SingletonDatabase const&) = delete;

	static SingletonDatabase& get()
	{
		static SingletonDatabase db;
		return db;
	}

	int getPopulation(std::string const& name) override
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

class SingletonRecordFinder
{
public:
	int getTotalPopulation(std::vector<std::string> capitals)
	{
		int result{0};
		for(auto& capital : capitals)
		{
			result += SingletonDatabase::get().getPopulation(capital);
		}
		return result;
	}
};

class DummyDatabase : public Database
{
public:
	int getPopulation(std::string const& capital) override
	{
		auto x = m_capitals[capital];
		std::cout << capital << x << '\n';
		return x;
	}

	DummyDatabase()
	{
		m_capitals["alpha"] = 1000;
		m_capitals["beta"]  = 2000;
		m_capitals["gamma"] = 3000;
	}

private:
	std::map<std::string, int> m_capitals;
};

class ConfigurableRecordFinder
{
public:
	ConfigurableRecordFinder(Database& aDb)
		: db{aDb}
	{}

	int getTotalPopulation(std::vector<std::string> capitals)
	{
		int result{0};
		for(auto const& capital : capitals)
		{
			result += db.getPopulation(capital);
		}
		return result;
	}

private:
	Database& db;
};

// NOT good. Too dependent on the real database that might change.
TEST(RecordFinderTests, SingletonRecordFinderTests)
{
	SingletonRecordFinder rf;
	std::vector<std::string> vec{"budapest", "bucharest"};
	EXPECT_EQ(5000 + 2000, rf.getTotalPopulation(vec));
}

// GOOD. Not dependent on the real database.
TEST(RecordFinderTests, ConfigurableRecordFinderTests)
{
	DummyDatabase db;
	ConfigurableRecordFinder rf(db);
	std::vector<std::string> vec{"alpha", "beta"};
	EXPECT_EQ(3000, rf.getTotalPopulation(vec));
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
