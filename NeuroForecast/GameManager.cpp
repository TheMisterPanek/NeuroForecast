#include "stdafx.h"
#include "GameManager.h"
#include "CommandInfo.h"
#include <iostream>

GameManager::GameManager(CommandInfo &firstCommand,CommandInfo& secondCommand, int firstCommandMoney, int secondCommandMoney)
{
	SetFirstCommandMoney(firstCommandMoney);
	SetSecondCommandMoney(secondCommandMoney);
	_firstCommand = &firstCommand;
	_secondCommand = &secondCommand;
}

GameManager::~GameManager()
{
}

double GameManager::GetFirstCommandMoney()
{
	return _firstCommandMoney;
}

void GameManager::SetFirstCommandMoney(double value)
{

	_firstCommandMoney = value;
}

double GameManager::GetSecondCommandMoney()
{
	return _secondCommandMoney;
}

void GameManager::SetSecondCommandMoney(double value)
{
	CorrectingMoney(value);
	_secondCommandMoney = value;

}

double GameManager::GetFirstCommandChance()
{
	return  (double)(_firstCommandMoney / GetBankMoney());
}

double GameManager::GetSecondCommandChance()
{
	return (double)(_secondCommandMoney / GetBankMoney());
}

double GameManager::GetBankMoney()
{
	return _firstCommandMoney + _secondCommandMoney;
}

void GameManager::BetOnFirstCommand(int value)
{
	_firstCommand += value;
}

void GameManager::BetOnSecondCommand(int value)
{
	_secondCommand += value;
}

CommandInfo GameManager::GetWinner(double userBet)
{
	CommandInfo * winner = nullptr;

	double GenericWin = (GetBankMoney() + userBet);


	double percentWinMoneyFirstCommand = (userBet) / (userBet + _firstCommandMoney);
	double WinFirstCommand = GenericWin*percentWinMoneyFirstCommand ;

	double percentWinMoneySecondCommand = (userBet) / (userBet + _secondCommandMoney);
	double WinSecondCommand = GenericWin*percentWinMoneySecondCommand;


	double absoluteFirstWin = WinFirstCommand*_firstCommand->GetChanceOfVictory() - userBet*_secondCommand->GetChanceOfVictory();
	double absoluteSecondWin = WinSecondCommand*_secondCommand->GetChanceOfVictory() - userBet*_firstCommand->GetChanceOfVictory();

	_coefficientFirstCommand = absoluteFirstWin;
	_coefficientSecondCommand = absoluteSecondWin;

	if (absoluteFirstWin > absoluteSecondWin)
	{
		winner = _firstCommand;
	}
	else
	{
		winner = _secondCommand;
	}
	return *winner;
}

double GameManager::GetCoefficientFirstCommand()
{
	return _coefficientFirstCommand;
}

double GameManager::GetCoefficientSecondCommand()
{
	return _coefficientSecondCommand;
}

double GameManager::CorrectingMoney(double money)
{
	if (money < 0)
	{
		money = 0;
	}
	return money;
}
