#include "Renderer.h"

#include <iostream>

#include "GL/glut.h"

// cringe
#define GL_DRAW(Type, VerticesCode) \
	glBegin(Type); \
	VerticesCode \
	glEnd();


const int DrawInfo::PolygonMode = GL_POLYGON;


/* Ініціалізація початкових параметрів */
/* Налаштування параметрів прикладної програми */
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

void Renderer::Run()
{
	glutPrepareMainLoop();

	while (glutIsRunning())
	{
		glutUpdateMainLoop();

		glClear(GL_COLOR_BUFFER_BIT);

		Draw();
	}
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

	glClear(GL_COLOR_BUFFER_BIT);

	Draw();
}

void Renderer::AddToDraw(const DrawInfo& DrawInfo)
{
	DrawBuffer.emplace_back(DrawInfo);
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

	glFlush();
}

