#pragma once

#include "Core/CoreAPI.h"

#include <string>

class CORE_API Window
{
public:
	Window(
		int InWidth, 
		int InHeight, 
		const std::string& WindowTitle = "NewWindow", 
		int argc = 0, 
		char** argv = nullptr);

public:
	inline int GetWidth() const;
	inline int GetHeight() const;
};

