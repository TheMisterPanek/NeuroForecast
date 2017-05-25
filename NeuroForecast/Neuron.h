#pragma once

#include <vector>
#include <string>
#include "CommandInfo.h"
#include "CommandCollection.h"
#include "Randomizer.h"

using namespace std;
class Neuron
{
public:
	Neuron(string name,CommandCollection & commandCollection);
	Neuron(string name);
	~Neuron();
	
	void SaveNeuron();
	void SaveNeuron(string path);

	void LoadNeuron();
	void LoadNeuron(string path);


	double GetChoise(CommandInfo&);

	string getName();
	void setName(string value);

	
private:
	string _name;


	CommandCollection * command;
	bool TestDo(CommandInfo command, Randomizer rnd);
};

