#pragma once
#include <string>
#include <sstream>

using namespace std;

class CommandInfo
{
public:
	CommandInfo(string name, int countWin, int numberOfGames);
	
	~CommandInfo();

	string GetName();
	void SetName(string newName);

	void Win();
	void Lose();

	int GetCountWin();
	void SetCountWin(int newCount);

	int GetCountLose();

	int GetNumberOfGames();
	void SetNumberOfGames(int newNumberOfGames);

	float GetChanceOfVictory();

	static CommandInfo ParseCommand(string line);

	string toString();

private:
	string _name;
	int _countWin;
	int _numberOfGames;

};

