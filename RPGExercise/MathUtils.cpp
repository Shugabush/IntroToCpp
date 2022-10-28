#include "MathUtils.h"

#include <cstdlib>
#include <ctime>

void SeedRandom(unsigned * seed)
{
	// if null, use time
	if (seed == nullptr)
	{
		std::srand(std::time(nullptr));
	}
	// else, use the value pointed to by seed
	else
	{
		std::srand(*seed);
	}
}

int RandomRange(int minInclusive, int maxExclusive)
{
	return minInclusive + (std::rand() % (maxExclusive - minInclusive));
}

int Clamp(int value, int min, int max)
{
	if (value < min)
	{
		value = min;
	}
	else if (value > max)
	{
		value = max;
	}
	return value;
}