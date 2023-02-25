#include "Renderer.h"

#include <iostream>

#include "GL/glut.h"

void* DrawTextInfo::DefaultFont = GLUT_BITMAP_9_BY_15;

const int DrawInfo::PolygonMode = GL_POLYGON;


/* ������������ ���������� ��������� */
/* ������������ ��������� ��������� �������� */
Renderer::Renderer(const Window* InDrawWindow)
	: DrawWindow(InDrawWindow)
{
	SetBackgroundColor(BackgroundColor);
}

void Renderer::SetBackgroundColor(const Color& NewBackgroundColor)
{
	BackgroundColor = NewBackgroundColor;
	glClearColor(
		NewBackgroundColor.R,
		NewBackgroundColor.G,
		NewBackgroundColor.B,
		NewBackgroundColor.A
	);
}

inline bool Renderer::IsRunning()
{
	return glutIsRunning();
}

void Renderer::Prepare()
{
	glutPrepareMainLoop();
}

void Renderer::Update()
{
	glutUpdateMainLoop();

	bool bDrawBufferEmpty = DrawBuffer.empty();

	Draw();

	glFlush();
	if (!bDrawBufferEmpty)
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}
}

void Renderer::AddToDraw(const DrawInfo& DrawInfo)
{
	DrawBuffer.emplace_back(DrawInfo);
}

void Renderer::AddToDraw(const DrawTextInfo& DrawTextInfo)
{
	DrawTextBuffer.emplace_back(DrawTextInfo);
}

void Renderer::Draw()
{
	for (DrawInfo& DrawInfo : DrawBuffer)
	{
		glColor4fv(DrawInfo.Color.RGBA);

		glBegin(DrawInfo.DrawMode);
		for (Vector3d& Vertex : DrawInfo.Vertices)
		{
			glVertex3dv(Vertex.XYZ);
		}
		glEnd();
	}
	DrawBuffer.clear();

	for (DrawTextInfo& DrawTextInfo : DrawTextBuffer)
	{
		glColor4fv(DrawTextInfo.Color.RGBA);

		glRasterPos3dv(DrawTextInfo.Position.XYZ);

		for (char Character : DrawTextInfo.Text)
		{
			glutBitmapCharacter(DrawTextInfo.Font, Character);
		}
	}

	glFlush();
}

