#pragma once

#include "Core/Types/CoreTypes.h"

#include <vector>
#include <string>

struct CORE_API DrawInfo
{
public:
	/** Modes: */
	static const int PolygonMode;

public:
	Color Color;

	std::vector<Vector3d> Vertices;

	int DrawMode = PolygonMode;
};

struct CORE_API DrawTextInfo
{
public:
	Color Color;

	Vector3d Position;

	std::string Text;

	void* Font = DefaultFont;

private:
	static void* DefaultFont;
};