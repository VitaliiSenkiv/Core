#pragma once

#define GL_DRAW(Type, VerticesCode) \
	glBegin(Type); \
	VerticesCode \
	glEnd();

#ifdef CORE_BUILD
#define CORE_API __declspec(dllexport)
#else
#define CORE_API __declspec(dllimport)
#endif // CORE_BULID

// TODO: Implemet this is just test
class CORE_API Renderer
{
public:
	Renderer(int argc, char** argv);

public:
	void Init();

	void SetDisplayFunction();
	void SetReshapeFunction();

	void Run();
};

