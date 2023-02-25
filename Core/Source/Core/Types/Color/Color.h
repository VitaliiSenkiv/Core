#pragma once

#include "Core/CoreAPI.h"

#include <string>

struct CORE_API Color
{
	/* Predefined colors */
	const static Color White;
	const static Color Red;
	const static Color Green;
	const static Color Blue;
	const static Color Black;

public:
	/* Ctors */
	Color() : Color(Color::Black) {};
	Color(float InR, float InG, float InB, float InA = 0.f) : R{ InR }, G{ InG }, B{ InB }, A{ InA } {};

	Color(const Color& OtherColor) : Color(OtherColor.R, OtherColor.G, OtherColor.B, OtherColor.A) {}

public:
	/* Fabrick methods to generate random color */
	static Color MakeRandomColor();
	static Color MakeRandomColorWithAlpha();

	std::string GetHexCode();
	Color GetInversed();


public:
	union 
	{
		struct
		{
			/* Main colors */
			float R;
			float G;
			float B;

			/* Transparancy */
			float A;
		};

		float RGBA[4];
	};
};