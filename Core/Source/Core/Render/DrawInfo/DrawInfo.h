#pragma once

#include "Core/Types/CoreTypes.h"
#include "Core/Types/Transform/Generator/TransformGenerator.h"

#include <vector>
#include <string>

struct TransformGenerator;

constexpr int TransformMatrixElementsCount = 16;

struct CORE_API DrawInfo
{
public:
	DrawInfo()
	{
		TransformGenerator::CreateIdentity().GetRaw(TransformMatrix);
	}
	DrawInfo(const Color& InColor, const std::vector<Vector3d>& InVertices, int InDrawMode)
		: Color(InColor), Vertices(InVertices), DrawMode(InDrawMode)
	{
		TransformGenerator::CreateIdentity().GetRaw(TransformMatrix);
	}

public:
	void SetTransform(const TransformGenerator& TransformGenerator);

	double* GetTransformMatrix() { return TransformMatrix; }

public:
	/** Modes: */
	static const int PolygonMode;
	static const int LineStripMode;

public:
	Color Color;

	std::vector<Vector3d> Vertices;

	int DrawMode = PolygonMode;

protected:
	using Matrix4 = double[TransformMatrixElementsCount];

	Matrix4 TransformMatrix;
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