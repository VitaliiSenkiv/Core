#include "Math.h"

#include <ctime>

Math::RandInitializer Math::StaticRandInitializer;

Math::RandInitializer::RandInitializer()
{
	srand(time(nullptr));
}
