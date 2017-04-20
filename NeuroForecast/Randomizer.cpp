#include "stdafx.h"
#include "Randomizer.h"
#include <random>

using namespace std;

Randomizer::Randomizer()
{
}


Randomizer::~Randomizer()
{
}

float Randomizer::GetPercent()
{
	return (rand() % 100)/100.0f;
}
