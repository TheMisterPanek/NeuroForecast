#include "stdafx.h"
#include "CommandInfo.h"



CommandInfo::CommandInfo(string name="",int countWin = 0,int numberOfGames =0)
{
	SetName(name);
	SetCountWin(countWin);
	SetNumberOfGames(numberOfGames);
}




CommandInfo::~CommandInfo()
{
	
}

string CommandInfo::GetName()
{
	return _name;
}

#pragma region Accessors



void CommandInfo::SetName(string newName)
{
	_name = newName;
}

void CommandInfo::Win()
{
	_countWin++;
	_numberOfGames++;
}

void CommandInfo::Lose()
{
	_numberOfGames++;
}

int CommandInfo::GetCountWin()
{
	return _countWin;
}

void CommandInfo::SetCountWin(int newCount)
{
	if (newCount < 0)
		newCount = 0;
	_countWin = newCount;
}

int CommandInfo::GetCountLose()
{
	return GetNumberOfGames()-GetCountWin();
}


int CommandInfo::GetNumberOfGames()
{
	return _numberOfGames;
}

void CommandInfo::SetNumberOfGames(int newNumberOfGames)
{
	if (newNumberOfGames < 0)
		newNumberOfGames = 0;
	_numberOfGames = newNumberOfGames;
}

float CommandInfo::GetChanceOfVictory()
{
	if (_numberOfGames != 0)
		return (float)_countWin / (float)_numberOfGames;
}

CommandInfo CommandInfo::ParseCommand(string line)
{
	std::istringstream is(line); // открываем поток ввода из строки
	std::string name;
	int games, wins;
	is >> name >> games >> wins; // считываем как из обычного потока ввода

	return CommandInfo(name, games, wins);
}




string CommandInfo::toString()
{
	string text = _name + " ";
	text += "Win:" + to_string(GetCountWin());
	text += " ";
	text += "Number of games:" + to_string(GetNumberOfGames());
	return text;
}

#pragma endregion
