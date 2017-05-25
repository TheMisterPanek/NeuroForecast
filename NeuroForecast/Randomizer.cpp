#include "stdafx.h"
#include "Randomizer.h"
#include <random>
#include <ctime>

using namespace std;

Randomizer::Randomizer()
{
	srand(time(0));
}


Randomizer::~Randomizer()
{
}

float Randomizer::GetPercent()
{
	return (rand()%100)/100.0;
}
