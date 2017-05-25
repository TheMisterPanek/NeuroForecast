#pragma once

#include "Neuron.h"
#include <vector>
#include <string>

using namespace std;

class NeuronFactory
{
public:
	NeuronFactory();
	~NeuronFactory();

	Neuron CreateNew(CommandCollection*);
	//Neuron CreateNew(char* neuronName);


private:
	vector<Neuron> _neurons;
	int indexator;
};

