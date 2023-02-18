#include "Math.h"

#include <cmath>
#include <ctime>

Math::RandInitializer Math::StaticRandInitializer;

Math::RandInitializer::RandInitializer()
{
	srand(time(nullptr));
}

float Math::RandRange(float Min, float Max)
{
	return Min + (Max - Min) * FRand();
}

float Math::FRand()
{
	return Rand() / RAND_MAX;
}

int Math::Rand()
{
	return rand();
}
