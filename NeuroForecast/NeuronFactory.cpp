#include "stdafx.h"
#include "NeuronFactory.h"
#include <string>



NeuronFactory::NeuronFactory()
{
	indexator = 0;
}


NeuronFactory::~NeuronFactory()
{
	
}

Neuron NeuronFactory::CreateNew(CommandCollection * collection)
{
	string neuron_name = "Neuron_" + to_string(indexator++);
	Neuron * neuron = new Neuron(neuron_name, *collection);
	_neurons.push_back(*neuron);
	return *neuron;
}

//Neuron NeuronFactory::CreateNew(char * neuronName)
//{
//	//Neuron neuron = Neuron();
//	return Neuron(neuronName,CommandCollection());
//}
