#include "Timer.h"

#include <ctime>

Timer::Timer()
{
	RegisterCurrentTime();
}

void Timer::RegisterCurrentTime()
{
	RegistredClock = std::clock();
}

double Timer::GetElapsedTime()
{
	Clock CurrentClock = std::clock();

	return (double)(CurrentClock - RegistredClock) / CLOCKS_PER_SEC;
}
