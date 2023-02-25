#include "Color.h"
#include <sstream>
#include <iomanip>

#include <Core/Math/Math.h>

constexpr int ByteMaxValue = 255;

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

std::string Color::GetHexCode()
{
	std::stringstream StringStream;
	StringStream << "#" << std::hex << int(ByteMaxValue * R) << int(ByteMaxValue * G) << int(ByteMaxValue * B);
	return StringStream.str();
}

Color Color::GetInversed()
{
	return Color(1-R, 1-G, 1-B);
}
