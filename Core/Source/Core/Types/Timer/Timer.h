#pragma once

#include "Core/CoreAPI.h"

class CORE_API Timer
{
private:
	using Clock = unsigned long;

public:
	Timer();

public:
	/** Register new timestamp */
	void RegisterCurrentTime();

	/** Returns time passed from last registred timestamp */
	double GetDeltaTime();

private:
	Clock RegistredClock;
};

