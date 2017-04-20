// NeuroForecast.cpp: ���������� ����� ����� ��� ����������� ����������.
//


#include "stdafx.h"
#include <iostream>
#include "NeuroForecast.h"
#include "CommandInfo.h";
#include "CommandCollection.h"
#include "Neuron.h"
#include <stdio.h>


using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	CommandInfo * commandFirst = new CommandInfo("������� 1", 5, 10);
	CommandInfo * commandSecond = new CommandInfo("������� 2", 6, 11);
	
	CommandCollection * collection = new CommandCollection();

	collection->Add(*commandFirst);
	collection->Add(*commandFirst);
	collection->Add(*commandSecond);

	cout << collection->ToString()<<endl;

	collection->Remove(*commandFirst);
	cout << "���������� ������ � ������:" << collection->Count() << endl;
	cout << collection->ToString()<<endl;
	delete collection;
	

	cout << "������� 1 ����� ���������� " << commandFirst ->GetChanceOfVictory() << endl;
	cout << "������� 2 ����� ���������� " << commandSecond ->GetChanceOfVictory()<< endl;

	Neuron * neuron = new Neuron();
	const int countGames = 10;
	bool games[2][countGames];
	for (int i = 0; i < countGames; i++)
	{
		games[0][i] = neuron->GetChoise(*commandFirst);
		games[1][i] = neuron->GetChoise(*commandSecond);

	}

	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < countGames; i++)
		{
			cout << games[j][i] << "\t";
		}
		cout << endl;
	}


	delete neuron;


	delete commandFirst;
	delete commandSecond;
	cout << "������ ���";
	cout << endl;
	return 0;
}


