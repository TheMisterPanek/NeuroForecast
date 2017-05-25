#pragma once
#include "CommandInfo.h"
class GameManager
{
public:
	GameManager(CommandInfo& firstCommand,CommandInfo& secondCommand ,int firstCommandMoney,int secondCommandMoney);
	~GameManager();

	double GetFirstCommandMoney();
	void SetFirstCommandMoney(double value);

	double GetSecondCommandMoney();
	void SetSecondCommandMoney(double value);

	double GetFirstCommandChance();
	double GetSecondCommandChance();

	double GetBankMoney();


	void BetOnFirstCommand(int value);
	void BetOnSecondCommand(int value);

	CommandInfo GetWinner(double userbet);

	double GetCoefficientFirstCommand();
	double GetCoefficientSecondCommand();


private:
	double _firstCommandMoney;
	double _secondCommandMoney;
	double _coefficientFirstCommand;
	double _coefficientSecondCommand;

	CommandInfo * _firstCommand;
	CommandInfo * _secondCommand;
	double CorrectingMoney(double money);
};

