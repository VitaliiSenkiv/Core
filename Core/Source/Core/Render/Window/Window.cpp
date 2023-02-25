#include "Window.h"

#include "GL/glut.h"

void HandleReshape(int NewWidth, int NewHeight);

Window::Window(
	int InWidth, 
	int InHeight, 
	const std::string& WindowTitle, 
	int argc, 
	char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(InWidth, InHeight);
	glutCreateWindow(WindowTitle.c_str());

	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(0.0, InWidth, 0.0, InHeight);  // ������ ����

	glutReshapeFunc(&HandleReshape);
}

inline int Window::GetWidth() const
{
	return glutGet(GLUT_WINDOW_WIDTH);
}
inline int Window::GetHeight() const
{
	return glutGet(GLUT_WINDOW_HEIGHT);
}

/* ������������� ���� � ��� ���� ���� ������ */
void HandleReshape(int NewWidth, int NewHeight)
{
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluOrtho2D(0.0, GLdouble(NewWidth), 0.0, GLdouble(NewHeight));

	/* �������� ���� */
	glClear(GL_COLOR_BUFFER_BIT);
}