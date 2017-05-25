// NeuroForecast.cpp: ���������� ����� ����� ��� ����������� ����������.
//


#include "stdafx.h"
#include <iostream>
#include "NeuroForecast.h"
#include "CommandInfo.h"
#include "CommandCollection.h"
#include "Neuron.h"
#include <stdio.h>
#include "FileWorker.h"
#include "GameManager.h"
#include "NeuronFactory.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");

	NeuronFactory factory = NeuronFactory();

	CommandCollection collection = CommandCollection();
	collection.Add(CommandInfo("������ �������", 0, 4));
	collection.Add(CommandInfo("������ �������", 1, 5));
	collection.Add(CommandInfo("������ �������", 2, 4));

	vector<Neuron> neurons =  vector<Neuron>();

	for (int i = 0; i < 5; i++)
	{
		neurons.push_back(factory.CreateNew(&collection));
	}
	
	for (int i = 0; i < neurons.size(); i++)
	{
		neurons[i].SaveNeuron();
	}

	return 0;

}


