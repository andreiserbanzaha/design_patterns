#include <iostream>

class Game
{
public:
	Game(int numberOfPlayers) : _numberOfPlayers{numberOfPlayers} {}

	void run()
	{
		start();
		while (!haveWinner()) { takeTurn(); }
		std::cout << "Player " << getWinner() << " is the winner!\n";
	}

protected:
	virtual void start() = 0;
	virtual bool haveWinner() = 0;
	virtual void takeTurn() = 0;
	virtual int getWinner() = 0;

	int _currentPlayer{0};
	int _numberOfPlayers;
};

class Chess : public Game
{
public:
	Chess() : Game(2) {}

protected:
	void start() override
	{
		std::cout << "starting a game of chess with " 
			<< _numberOfPlayers << " players.\n";
	}

	bool haveWinner()
	{
		return _turn == _maxNumberOfTurns;
	}

	void takeTurn()
	{
		std::cout << "Turn " << _turn << " taken by player " << _currentPlayer << '\n';
		++_turn;
		_currentPlayer = (_currentPlayer + 1) % _numberOfPlayers;
	}

	int getWinner()
	{
		return _currentPlayer;
	}

private:
	int _turn{0};
	int _maxNumberOfTurns{10};
};

int main()
{
	Chess chess;
	chess.run();

	return 0;
}
