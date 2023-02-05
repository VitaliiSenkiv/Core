#pragma once

#include "Core/CoreAPI.h"
#include "Core/Types/CoreTypes.h"
#include "Core/Render/Window/Window.h"

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

class CORE_API Renderer
{
public:
	Renderer(const Window* InDrawWindow);

public:
	void SetBackgroundColor(const Color& NewBackgroundColor);

	void Run();

	inline bool IsRunning();
	void Prepare();
	void Update();

	void AddToDraw(const DrawInfo& DrawInfo);

private:
	void Draw();

private:
	Color BackgroundColor;

	const Window* DrawWindow;

	std::vector<DrawInfo> DrawBuffer;
};

