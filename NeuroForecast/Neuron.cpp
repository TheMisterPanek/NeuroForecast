#include "stdafx.h"
#include "Neuron.h"
#include "Randomizer.h"
#include "FileWorker.h"

Neuron::Neuron(string name,CommandCollection & collection)
{
	command = &collection;
	setName(name);
}

Neuron::Neuron(string name)
{
	setName(name);
	command = new CommandCollection();
}


Neuron::~Neuron()
{
}

void Neuron::SaveNeuron()
{
	SaveNeuron("Neuron\\" + _name + ".txt");
}

void Neuron::SaveNeuron(string path)
{
	string output = "";
	for (int i = 0; i < command->Count(); i++)
	{
		output += (*command)[i].toString();
		output += "\n";
	}
	
	FileWorker * fileWorker = new FileWorker();
	fileWorker->WriteAllText(path, output);
	delete fileWorker;
}

void Neuron::LoadNeuron()
{
	LoadNeuron("Neuron\\" + _name + ".txt");
}

void Neuron::LoadNeuron(string path)
{

}

double Neuron::GetChoise(CommandInfo& command) {
	int countTrue = 0;
	int countGames = 1000;
	Randomizer rnd = Randomizer();
	for (int i = 0; i < countGames; i++)
	{
		if (TestDo(command,rnd))
		{
			countTrue++;
		}
	}
	return (double)countTrue/1000;
}

string Neuron::getName()
{
	return _name;
}

void Neuron::setName(string value)
{
	if (value.size() > 0)
	{
		_name = value;
	}
}

bool Neuron::TestDo(CommandInfo command,Randomizer rnd)
{
	float percent = rnd.GetPercent();
	return percent > command.GetChanceOfVictory();
}



