#include "DrawInfo.h"

#include "GL/glut.h"

void* DrawTextInfo::DefaultFont = GLUT_BITMAP_9_BY_15;

const int DrawInfo::PolygonMode = GL_POLYGON;
const int DrawInfo::LineStripMode = GL_LINE_STRIP;
const int DrawInfo::LineLoopMode = GL_LINE_LOOP;

void DrawInfo::SetTransform(const TransformGenerator& TransformGenerator)
{
	TransformGenerator.GetRaw(TransformMatrix);
}
