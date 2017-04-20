#pragma once

#include <vector>
#include <string>
#include "CommandInfo.h"
#include "CommandCollection.h"

using namespace std;
class Neuron
{
public:
	Neuron();
	~Neuron();
	
	bool GetChoise(CommandInfo&);

	
private:
	CommandCollection command;
	bool TestDo(CommandInfo);
};

