#pragma once

#include <cmath>

constexpr float Pi = 3.1415926535897932f;
constexpr float DegreesInRadian = 180.f / Pi;
constexpr float RadiansInDegree = Pi / 180.f;

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
	static float RandRange(float Min, float Max) { return Min + (Max - Min) * FRand(); }
	/** Returns randon number in range [0.0, 1.0] */
	static float FRand() { return Rand() / (float)RAND_MAX; }
	/** Returns random value in range [0, RAND_MAX] */
	static int Rand() { return rand(); }

	static float RadiansToDegrees(float Radians) { return Radians * DegreesInRadian; }
	static float DegreesToRadians(float Degrees) { return Degrees * RadiansInDegree; }

	static float Sin(float Radians)		{ return sin(Radians); }
	static float SinDeg(float Degrees)	{ return Sin(DegreesToRadians(Degrees)); }
	static float Cos(float Radians)		{ return cos(Radians); }
	static float CosDeg(float Degrees)	{ return Cos(DegreesToRadians(Degrees));  }

private:
	/** This object is used to initialize random for Math static class (this is one of possible ways to create static ctors) */
	static RandInitializer StaticRandInitializer;
};

