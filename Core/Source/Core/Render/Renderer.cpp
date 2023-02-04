#include "Renderer.h"

#include "GL/glut.h"

#include <iostream>

void DrawTest();
void HandleReshape(int NewWidth, int NewHeight);

Renderer::Renderer(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 300);
	glutCreateWindow("Графічні об’єкти OpenGL");

	Init();
}


/* Ініціалізація початкових параметрів */
/* Налаштування параметрів прикладної програми */
void Renderer::Init()
{
	glClearColor(.08f, .08f, .087f, 0);      // Колір вікна

	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(0.0, 400, 0.0, 300);  // Розміри вікна

	//SetDisplayFunction();
	SetReshapeFunction();
}

void Renderer::SetDisplayFunction()
{
	glutDisplayFunc(&DrawTest);
}

void Renderer::SetReshapeFunction()
{
	glutReshapeFunc(&HandleReshape);
}

void Renderer::Run()
{
	glutPrepareMainLoop();

	while (glutIsRunning())
	{
		glutUpdateMainLoop();

		glClear(GL_COLOR_BUFFER_BIT);

		DrawTest();
	}
	std::cout << "===================END===================";
}

/* Створення графічних об’єктів */
void DrawTest()
{
	glColor3f(.7f, .3f, .2f);

	static int movement = 0;

	GL_DRAW
	(
		GL_POLYGON,
		glVertex2d(50 + movement * 5, 50);
		glVertex2d(50 + movement * 5, 100);
		glVertex2d(100 + movement * 5, 100);
		glVertex2d(100 + movement * 5, 50);
		++movement;
	);

	glFlush();
}

/* Перемалювання вікна у разі зміни його розмірів */
void HandleReshape(int NewWidth, int NewHeight)
{
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluOrtho2D(0.0, GLdouble(NewWidth), 0.0, GLdouble(NewHeight));

	/* Очищення вікна */
	glClear(GL_COLOR_BUFFER_BIT);
}