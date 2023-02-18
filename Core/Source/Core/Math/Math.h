#pragma once

class Math
{
private:
	/** Helper class for random initialization */
	struct RandInitializer
	{
		RandInitializer();
	};

public:
	/** Forbid instancing of math */
	Math() = delete;

public:
	/** Main methods */

	/** Returns rand value in range [Min, Max] */
	static float RandRange(float Min, float Max);

	/** Returns randon number in range [0.0, 1.0] */
	static float FRand();

	/** Returns random value in range [0, RAND_MAX] */
	static int Rand();

private:
	/** This object is used to initialize random for Math static class (this is one of possible ways to create static ctors) */
	static RandInitializer StaticRandInitializer;
};

