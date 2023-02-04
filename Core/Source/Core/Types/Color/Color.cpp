#include "Color.h"
#include <stdlib.h>
#include <time.h>

const Color Color::Red = Color(1.f, 0.f, 0.f);
const Color Color::Green = Color(0.f, 1.f, 0.f);
const Color Color::Blue = Color(0.f, 0.f, 1.f);
const Color Color::Black = Color(0.f, 0.f, 0.f);

constexpr int RandomizationRange = 256;
constexpr int MaxRandomValue = RandomizationRange - 1;

/* Generates random color with alpha = 0 */
Color Color::MakeRandomColor()
{
	srand(time(0));

	// TODO: create rand range in math core
	float R = float(rand() % RandomizationRange) / MaxRandomValue;
	float G = float(rand() % RandomizationRange) / MaxRandomValue;
	float B = float(rand() % RandomizationRange) / MaxRandomValue;

	return Color(R, G, B);
}

/* Generates random color with random alpha */
Color Color::MakeRandomColorWithAlpha()
{
	Color RandomColor = MakeRandomColor();

	RandomColor.A = float(rand() % RandomizationRange) / MaxRandomValue;

	return RandomColor;
}