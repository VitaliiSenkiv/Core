#pragma once

#include "Core/Types/CoreTypes.h"

struct CORE_API TransformGenerator
{
public:
	static TransformGenerator CreateIdentity();
	
public:
	TransformGenerator& Translate(const Vector3d& Translation);
	TransformGenerator& Rotate(float Angle, const Vector3d& RotationAxis);
	TransformGenerator& Scale(const Vector3d& Scale);

	void GetRaw(double* OutMatrix) const;

private:
	TransformGenerator() = default;
};
