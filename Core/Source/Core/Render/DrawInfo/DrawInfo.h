#pragma once

#include "Core/Types/CoreTypes.h"
#include <vector>

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