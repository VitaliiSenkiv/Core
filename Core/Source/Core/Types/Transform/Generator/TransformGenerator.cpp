#include "TransformGenerator.h"

#include "GL/glut.h"

TransformGenerator TransformGenerator::CreateIdentity()
{
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glLoadIdentity();

	return TransformGenerator();
}

TransformGenerator& TransformGenerator::Translate(const Vector3d& Translation)
{
	glTranslated(Translation.X, Translation.Y, Translation.Z);
	
	return *this;
}

TransformGenerator& TransformGenerator::Rotate(float Angle, const Vector3d& RotationAxis)
{
	glRotated(Angle, RotationAxis.X, RotationAxis.Y, RotationAxis.Z);

	return *this;
}

TransformGenerator& TransformGenerator::Scale(const Vector3d& Scale)
{
	glScaled(Scale.X, Scale.Y, Scale.Z);

	return *this;
}

void TransformGenerator::GetRaw(double* OutMatrix) const
{
	return glGetDoublev(GL_MODELVIEW_MATRIX, OutMatrix);
}
