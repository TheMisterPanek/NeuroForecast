#include "stdafx.h"
#include "Neuron.h"
#include "Randomizer.h"


Neuron::Neuron()
{
}


Neuron::~Neuron()
{
}

bool Neuron::GetChoise(CommandInfo & command)
{
	int countTrue = 0;
	int countGames = 100;
	for (int i = 0; i < countGames; i++)
	{
		if (TestDo(command))
		{
			countTrue++;
		}
	}
	return countTrue > countGames-(countGames/2);
}

bool Neuron::TestDo(CommandInfo command)
{
	float percent = Randomizer::GetPercent();
	return percent > command.GetChanceOfVictory();
}



