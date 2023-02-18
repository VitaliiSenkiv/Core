#pragma once

#include "Core/CoreAPI.h"
#include "Core/Types/CoreTypes.h"
#include "Core/Render/Window/Window.h"
#include "Core/Render/DrawInfo/DrawInfo.h"

#include <vector>

/**
 * Renderer is class used for drawing different objects (currently based on OpnGl(custom modified version of freeglut))
 * 
 * Exaple of use renderer:
 * 
 *   Window Window(WindowWidth, WindowHeight, "TestWin");
 *   
 *   Renderer Renderer(&Window);
 *   
 *   Renderer.Prepare();
 *   while (Renderer.IsRunning())
 *   {
 *       // Your code here
 *       // Renderer.AddToDraw()
 *       Renderer.Update();
 *   }
 */

class CORE_API Renderer
{
public:
	Renderer(const Window* InDrawWindow);

public:
	void SetBackgroundColor(const Color& NewBackgroundColor);

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

