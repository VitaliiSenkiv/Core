#include "Color.h"
#include <stdlib.h>
#include <time.h>

#include <Core/Math/Math.h>

const Color Color::White = Color(1.f, 1.f, 1.f);
const Color Color::Red = Color(1.f, 0.f, 0.f);
const Color Color::Green = Color(0.f, 1.f, 0.f);
const Color Color::Blue = Color(0.f, 0.f, 1.f);
const Color Color::Black = Color(0.f, 0.f, 0.f);


/* Generates random color with alpha = 0 */
Color Color::MakeRandomColor()
{
	float R = Math::FRand();
	float G = Math::FRand();
	float B = Math::FRand();

	return Color(R, G, B);
}

/* Generates random color with random alpha */
Color Color::MakeRandomColorWithAlpha()
{
	Color RandomColor = MakeRandomColor();

	RandomColor.A = Math::FRand();

	return RandomColor;
}